// 来源小节：21.9 Overloading the subscript operator
// 示例说明：给 IntList 增加 int* getList() 访问函数，外部写 list.getList()[2] = 3
//           即可读写元素。虽然能工作，但语法怪异，不符合数组下标的直觉。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：3

#include <iostream>

class IntList
{
private:
    int m_list[10]{};

public:
    int* getList() { return m_list; }
};

int main()
{
    // --- 原文示例片段 ---
    IntList list{};
    list.getList()[2] = 3;

    std::cout << list.getList()[2] << '\n'; // prints 3
    // --- 原文示例片段结束 ---

    return 0;
}
