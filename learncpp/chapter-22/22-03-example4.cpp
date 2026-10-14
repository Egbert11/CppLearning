// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：DynamicArray 模板——堆上动态数组，深拷贝语义
//           （拷贝构造用 std::copy_n，拷贝赋值有自赋值检查）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：
//   1 2 3
//   2 4 6
// 备注：本节代码为按原文描述重建（原 Example 4）。
// ============================================================
#include <algorithm> // for std::copy_n
#include <cassert>
#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T* m_array{};
    int m_length{};

public:
    DynamicArray(int length)
        : m_array{ new T[static_cast<std::size_t>(length)] }
        , m_length{ length }
    {
        assert(length >= 0);
    }

    ~DynamicArray() { delete[] m_array; }

    // Copy constructor -- deep copy
    DynamicArray(const DynamicArray& arr)
        : m_length{ arr.m_length }
    {
        m_array = new T[static_cast<std::size_t>(m_length)];
        std::copy_n(arr.m_array, m_length, m_array);
    }

    // Copy assignment -- deep copy
    DynamicArray& operator=(const DynamicArray& arr)
    {
        if (&arr == this)
            return *this;

        delete[] m_array;

        m_length = arr.m_length;
        m_array = new T[static_cast<std::size_t>(m_length)];
        std::copy_n(arr.m_array, m_length, m_array);
        return *this;
    }

    T& operator[](int index) { return m_array[index]; }
    const T& operator[](int index) const { return m_array[index]; }

    int getLength() const { return m_length; }
};

int main()
{
    DynamicArray<int> src(3);
    src[0] = 1;
    src[1] = 2;
    src[2] = 3;

    DynamicArray<int> copy{ src }; // deep copy
    copy[0] = 2;
    copy[1] = 4;
    copy[2] = 6;

    for (int i = 0; i < src.getLength(); ++i)
        std::cout << src[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < copy.getLength(); ++i)
        std::cout << copy[i] << ' ';
    std::cout << '\n';

    return 0;
}
