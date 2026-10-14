// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：Auto_ptr4 在拷贝构造/拷贝赋值之外，新增 noexcept 的
//           移动构造与移动赋值；对右值（临时对象）会走移动路径，
//           大幅减少分配/析构次数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出（较老编译器，2 行）：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>

template <typename T>
class Auto_ptr4
{
    T* m_ptr{};
public:
    Auto_ptr4(T* ptr = nullptr) : m_ptr{ ptr } {}
    ~Auto_ptr4() { delete m_ptr; }

    // Copy constructor -- deep copy
    Auto_ptr4(const Auto_ptr4& a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    // Move constructor
    Auto_ptr4(Auto_ptr4&& a) noexcept
        : m_ptr{ a.m_ptr }
    {
        a.m_ptr = nullptr; // we'll talk more about this line below
    }

    // Copy assignment -- deep copy
    Auto_ptr4& operator=(const Auto_ptr4& a)
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        return *this;
    }

    // Move assignment
    Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
    {
        // self-assignment check
        if (&a == this)
            return *this;

        // if the destination already has a value, free it (or use swap)
        delete m_ptr;

        // steal the resource
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr; // we'll talk more about this below
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
    Auto_ptr4<Resource> res(new Resource());
    return res; // this return value will invoke the move constructor (or be elided)
}

int main()
{
    Auto_ptr4<Resource> mainres;
    mainres = generateResource(); // this assignment will invoke the move assignment

    return 0;
}
