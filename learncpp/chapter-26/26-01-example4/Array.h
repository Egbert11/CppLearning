// ============================================================
// 来源小节：26.1 Template classes（原 Example 8 的三文件方案）
// 示例说明：类声明留在头文件里，成员函数定义留在 Array.cpp 里，再额外加一个
//           templates.cpp：它同时 #include 头文件和 .cpp，并用 template class
//           命令显式实例化所需的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 备注：代码取自原文 HTML 逐字抽取（此处的 Array.h 与 example3 相同）。
// ============================================================
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T> // added
class Array
{
private:
    int m_length{};
    T* m_data{}; // changed type to T

public:

    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{}; // allocated an array of objects of type T
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    // templated operator[] function defined below
    T& operator[](int index); // now returns a T&

    int getLength() const { return m_length; }
};

// Definition of Array<T>::operator[] moved into Array.cpp below

#endif
