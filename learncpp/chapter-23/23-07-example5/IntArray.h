#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm>          // for std::copy()
#include <cassert>            // for assert()
#include <cstddef>            // for std::size_t
#include <initializer_list>   // for std::initializer_list

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length)
        : m_length{ length }
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[static_cast<std::size_t>(length)]{};
    }

    IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
        : IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
    {
        // Now initialize our array from the list
        std::copy(list.begin(), list.end(), m_data);
    }

    // Delete the copy constructor and copy assignment to prevent shallow copies
    // (a list constructor makes the class tempting to assign from a temporary, which
    //  would otherwise shallow-copy the internal pointer).
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    ~IntArray()
    {
        delete[] m_data;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

#endif
