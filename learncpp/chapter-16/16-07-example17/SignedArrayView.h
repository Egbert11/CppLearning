// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：自定义视图类 SignedArrayView——包装任何可索引容器 T，
//           提供接受有符号索引的 operator[]，以及返回有符号长度的 ssize()。
//           在 C++20 之前，这可用于给容器提供有符号下标接口。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 备注：本节代码为按原文描述重建。配合 main.cpp 编译：
//       g++ -std=c++20 -Wall 16-07-example17/*.cpp
// ============================================================
#ifndef SIGNED_ARRAY_VIEW_H
#define SIGNED_ARRAY_VIEW_H

#include <cstddef> // for std::ptrdiff_t

// SignedArrayView provides a view of a container that supports signed indexing.
template <typename T>
class SignedArrayView // requires T to be an indexable container
{
private:
    T& m_array;

public:
    using Index = std::ptrdiff_t;

    SignedArrayView(T& array)
        : m_array{ array }
    {
    }

    // Overload operator[] to take a signed index
    constexpr auto& operator[](Index index)
    {
        return m_array[static_cast<typename T::size_type>(index)];
    }

    constexpr const auto& operator[](Index index) const
    {
        return m_array[static_cast<typename T::size_type>(index)];
    }

    // Return the length as a signed value
    constexpr auto ssize() const
    {
        return static_cast<Index>(m_array.size());
    }
};

#endif
