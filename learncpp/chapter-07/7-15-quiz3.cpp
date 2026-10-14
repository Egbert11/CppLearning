// 来源小节：7.x Chapter 7 summary and quiz（测验第 3 题）
// 示例说明：accumulate() 用静态局部变量保存累计和，返回截至当前的累计和。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
//
// 本节示例为按原文描述重建（对应原文 Quiz Question #3 的解答）。
// 预期输出：
// 4
// 7
// 9
// 10

#include <iostream>

int accumulate(int x)
{
    static int sum{ 0 }; // 注意：在整个程序启动时只初始化一次
    sum += x;
    return sum;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // 输出 4
    std::cout << accumulate(3) << '\n'; // 输出 7
    std::cout << accumulate(2) << '\n'; // 输出 9
    std::cout << accumulate(1) << '\n'; // 输出 10

    return 0;
}
