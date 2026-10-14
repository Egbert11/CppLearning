// 来源小节：7.11 Static local variables
// 示例说明：用静态局部变量实现唯一 ID 生成器。首次调用返回 0，其后 1、2……
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 3；原文只给出 generateID()，此处补 main 演示）。
// 预期输出：
// 0
// 1
// 2

#include <iostream>

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // 拷贝 s_itemID，递增真正的 s_itemID，然后返回拷贝中的值
}

int main()
{
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';

    return 0;
}
