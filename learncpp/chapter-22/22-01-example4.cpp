// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：智能指针雏形 Auto_ptr1——以组合方式持有一个裸指针，
//           在析构函数中 delete，并重载 * 与 -> 使其用起来像指针。
//           离开作用域时资源自动释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 4）。
// ============================================================
#include <iostream>

template <typename T>
class Auto_ptr1
{
    T* m_ptr{};
public:
    // 传指针进来，默认设为 nullptr
    Auto_ptr1(T* ptr = nullptr)
        : m_ptr{ ptr }
    {
    }

    // 析构函数（Destructor）会在对象离开作用域时自动调用
    ~Auto_ptr1()
    {
        // 因为我们不知道 T 会是什么，所以要假设它可以用被初始化的方式删除
        // 注意：对 nullptr 执行 delete 是安全的（什么也不做）
        delete m_ptr;
    }

    // Overload the dereference operator
    T& operator*() const { return *m_ptr; }
    // Overload the member dereference operator
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
    Auto_ptr1<Resource> res(new Resource()); // note: not explicitly calling the destructor

    return 0;
} // res goes out of scope here, and the allocated Resource is destroyed
