// 来源小节：21.9 Overloading the subscript operator
// 示例说明：IntList 的数据成员是私有数组，外部无法直接访问；只能用 setItem()/getItem()
//           这类访问函数读写元素。演示重载 operator[] 之前的窘境：参数顺序不直观
//           （是“把元素 2 设为 3”，还是“把元素 3 设为 2”？）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：3

#include <cassert>  // for assert()
#include <iostream>

class IntList
{
private:
    int m_list[10]{};

public:
    void setItem(int index, int value)
    {
        assert(index >= 0 && index < 10);
        m_list[index] = value;
    }

    int getItem(int index) const
    {
        assert(index >= 0 && index < 10);
        return m_list[index];
    }
};

int main()
{
    // --- 原文示例片段 ---
    IntList list{};
    list.setItem(2, 3); // is element 2 = 3, or element 3 = 2?
    std::cout << list.getItem(2) << '\n'; // prints 3
    // --- 原文示例片段结束 ---

    return 0;
}
