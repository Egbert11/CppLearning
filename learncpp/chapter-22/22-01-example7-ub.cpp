// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：未定义行为演示——按值把 Auto_ptr1 传入函数，形参是浅拷贝，
//           形参析构时删除了 Resource；调用方的 res1 随后析构时再次
//           删除同一对象，且 res1.m_ptr 已经悬垂。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出：
//   Resource acquired
//   Resource destroyed   <-- 形参 res 析构，资源已被删除
//   Resource destroyed   <-- res1 析构又删一次 -> UB，通常崩溃
// 备注：本节代码为按原文描述重建（原 Example 7）。属于未定义行为，
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

void passByValue(Auto_ptr1<Resource> res)
{
} // res 在此析构，删除它持有的 Resource

int main()
{
    Auto_ptr1<Resource> res1(new Resource());
    passByValue(res1); // res1 被浅拷贝进形参，资源所有权并未真正转移

    return 0; // res1 在此析构 -> 二次释放，UB
}
