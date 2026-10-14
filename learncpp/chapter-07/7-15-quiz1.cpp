// 来源小节：7.x Chapter 7 summary and quiz（测验第 1 题）
// 示例说明：修复版 —— 给 if (num < 0) 补上花括号，使"打印提示"与"num = -num;"两条语句
//           都在条件为真时执行。（原缺陷：num = -num; 在 if 之外，因而总会执行。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
//
// 本节示例为按原文描述重建（对应原文 Quiz Question #1 的解答）。需交互输入。
// 示例输出（输入 -5 时）：
// Enter a positive number: -5
// Negative number entered.  Making positive.
// You entered: 5
// 示例输出（输入 5 时）：
// Enter a positive number: 5
// You entered: 5

#include <iostream>

int main()
{
    std::cout << "Enter a positive number: ";
    int num{};
    std::cin >> num;

    if (num < 0)
    { // 需要这个块，才能让两条语句在 num < 0 时都执行
        std::cout << "Negative number entered.  Making positive.\n";
        num = -num;
    }

    std::cout << "You entered: " << num << '\n';

    return 0;
}
