// ============================================================
// 来源小节：26.1 Template classes（原 Example 6 的 Array.h，拆分版）
// 示例说明：把模板成员函数 operator[] 的定义移出到头文件之外（放到 Array.cpp），
//           这是“把模板拆成 .h/.cpp”的错误做法，会导致链接错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 备注：代码取自原文 HTML 逐字抽取。
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
