// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：直接初始化 vs 花括号初始化。列表初始化优先匹配"列表
//           构造函数"：IntArray a1(5) 走 IntArray(int)（长度 5）；
//           IntArray a2{ 5 } 走列表构造函数（长度 1，元素为 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   a1 length: 5
//   a2 length: 1
//   a2[0]: 5
// 备注：本节代码为按原文描述重建（原 Example 8；为自包含，内联一个
//       精简版 IntArray）。
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

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    ~IntArray() { delete[] m_data; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

int main()
{
    IntArray a1(5); // direct initialization calls IntArray(int) -> length 5
    IntArray a2{ 5 }; // list initialization calls IntArray(std::initializer_list<int>) -> length 1

    std::cout << "a1 length: " << a1.getLength() << '\n';
    std::cout << "a2 length: " << a2.getLength() << '\n';
    std::cout << "a2[0]: " << a2[0] << '\n';

    return 0;
}
