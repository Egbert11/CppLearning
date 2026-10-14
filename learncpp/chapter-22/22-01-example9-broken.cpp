// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：坏实践草图——想按值返回一个局部 Auto_ptr1，但 Auto_ptr1
//           只支持（隐式浅）拷贝，返回时会拷贝出第二个拥有者，
//           最终二次释放。这正说明"需要返回按值对象时仍会触发拷贝"，
//           从而引出真正的移动语义（C++11）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出：本程序会二次释放同一 Resource（UB），故仅作示意，勿运行。
// 备注：本节代码为按原文描述重建（原 Example 9）。
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

// --- 原文示例片段 ---
Auto_ptr1<Resource> generateResource()
{
    Auto_ptr1<Resource> res(new Resource());
    return res; // 按值返回会调用（隐式生成的）拷贝构造函数 -> 两个拥有者
}
// --- 原文示例片段 ---

int main()
{
    Auto_ptr1<Resource> mainres;
    mainres = generateResource(); // 又会触发拷贝赋值

    return 0;
}
