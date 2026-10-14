// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：在没有列表构造函数时的"手动兜底"做法——先用长度
//           构造，再逐个下标赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   5 4 3 2 1
// 备注：本节代码为按原文描述重建（原 Example 4）。
// ============================================================
#include <cassert>
#include <cstddef>
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

int main()
{
    IntArray array(5);

    // 手动逐个赋值
    array[0] = 5;
    array[1] = 4;
    array[2] = 3;
    array[3] = 2;
    array[4] = 1;

    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    return 0;
}
