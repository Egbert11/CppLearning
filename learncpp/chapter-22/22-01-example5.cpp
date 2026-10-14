// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：在函数中使用 Auto_ptr1<Resource>。无论函数是正常返回
//           还是中途提前返回，ptr 离开作用域时都会自动销毁资源。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出（输入非 0，如 5）：
//   Resource acquired
//   Enter an integer: 5
//   Hi!
//   Resource destroyed
// 预期输出（输入 0）：
//   Resource acquired
//   Enter an integer: 0
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 5）。
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

void sayHi()
{
    std::cout << "Hi!\n";
}

void someFunction()
{
    // This function knows how to allocate a Resource, but doesn't know how to delete it
    Auto_ptr1<Resource> ptr(new Resource()); // ptr now owns the Resource

    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return; // the function returns early

    // do stuff with ptr here

    sayHi();
} // when this function returns, ptr goes out of scope, and the Resource is destroyed

int main()
{
    someFunction();

    return 0;
}
