// 来源小节：21.9 Overloading the subscript operator
// 示例说明：与内建数组不同，重载的 operator[] 可以做越界检查——用 assert 断言下标在
//           合法范围内，用 std::size(m_list) 取数组长度（需要 <iterator>）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：3

#include <cassert>
#include <iostream>
#include <iterator> // for std::size

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
    int& operator[] (int index)
    {
        assert(index >= 0 && static_cast<std::size_t>(index) < std::size(m_list));

        return m_list[index];
    }
};

int main()
{
    IntList list{};
    list[2] = 3;

    std::cout << list[2] << '\n'; // prints 3

    return 0;
}
