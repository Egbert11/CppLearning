// ============================================================
// 来源小节：23.7 std::initializer_list（测验解答）
// 示例说明：为 IntArray 提供"列表赋值运算符"
//           operator=(std::initializer_list<int>)：当传入大小与当前
//           长度不同时重新分配，然后用 std::copy 拷贝值并返回 *this。
//           于是 `array = { ... }` 不再产生浅拷贝的临时对象，安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   5 4 3 2 1
//   1 3 5 7 9 11
// 备注：本节代码为按原文描述重建（原 Example 13 的驱动 + Example 14 的解答）。
// ============================================================
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>

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

    IntArray(std::initializer_list<int> list)
        : IntArray(static_cast<int>(list.size()))
    {
        std::copy(list.begin(), list.end(), m_data);
    }

    ~IntArray() { delete[] m_data; }

    // A copy assignment operator that takes a list
    IntArray& operator=(std::initializer_list<int> list)
    {
        // If the new list is a different size, reallocate
        int length{ static_cast<int>(list.size()) };
        if (length != m_length)
        {
            delete[] m_data;
            if (length > 0)
                m_data = new int[static_cast<std::size_t>(length)]{};
            else
                m_data = nullptr;
            m_length = length;
        }

        // Now copy the elements
        std::copy(list.begin(), list.end(), m_data);

        return *this;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

int main()
{
    IntArray array { 5, 4, 3, 2, 1 }; // initializer list
    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    array = { 1, 3, 5, 7, 9, 11 };

    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    return 0;
}
