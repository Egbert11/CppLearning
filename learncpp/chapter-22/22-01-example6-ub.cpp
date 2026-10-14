// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：未定义行为演示——编译器隐式生成的拷贝构造函数对 Auto_ptr1
//           做浅拷贝，res2 与 res1 指向同一个 Resource；两者析构时
//           都会 delete 同一对象，发生二次释放（double free）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出：
//   Resource acquired
//   Resource destroyed
//   Resource destroyed   <-- 对同一对象释放两次，随后通常崩溃
// 备注：本节代码为按原文描述重建（原 Example 6）。属于未定义行为，
//       实际结果依实现而定，请勿运行/勿照抄。
// ============================================================
#include <iostream>

template <typename T>
class Auto_ptr1
{
    T* m_ptr{};
public:
    Auto_ptr1(T* ptr = nullptr) : m_ptr{ ptr } {}
    ~Auto_ptr1() { delete m_ptr; }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    Auto_ptr1<Resource> res1(new Resource());

    // 编译器隐式生成的拷贝构造函数做浅拷贝：res2.m_ptr == res1.m_ptr
    Auto_ptr1<Resource> res2(res1);

    return 0;
} // 两个析构函数都会 delete 同一个 Resource -> 未定义行为
