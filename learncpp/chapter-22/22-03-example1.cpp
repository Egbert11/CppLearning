// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：Auto_ptr3 提供"深拷贝"的拷贝构造与拷贝赋值。按值从
//           generateResource() 返回、再赋值给 res2，会发生多次分配/析构。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：
//   Resource acquired
//   Resource acquired
//   Resource destroyed
//   Resource destroyed
// 原文描述：没有移动语义时，按值返回 + 赋值会引发（多次）深拷贝，
//   因而出现多次 acquire/destroy；实测（g++ -std=c++20）因 C++17 对
//   "返回临时对象"强制拷贝省略，故为 2 次 acquire / 2 次 destroy。
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <iostream>

template <typename T>
class Auto_ptr3
{
    T* m_ptr{};
public:
    Auto_ptr3(T* ptr = nullptr) : m_ptr{ ptr } {}
    ~Auto_ptr3() { delete m_ptr; }

    // Copy constructor -- deep copy
    Auto_ptr3(const Auto_ptr3& a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    // Copy assignment -- deep copy
    Auto_ptr3& operator=(const Auto_ptr3& a)
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
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

Auto_ptr3<Resource> generateResource()
{
    Auto_ptr3<Resource> res(new Resource());
    return res; // this return value will invoke the copy constructor
}

int main()
{
    Auto_ptr3<Resource> mainres;
    mainres = generateResource(); // this assignment will invoke the copy assignment

    return 0;
}
