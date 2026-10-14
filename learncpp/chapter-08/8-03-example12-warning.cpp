// 来源小节：8.3 Common if statement problems
// 示例说明：常见错误——把相等比较 operator== 误写成赋值 operator=。
//           x = 0 会先把 x 赋为 0，表达式结果为 0（布尔假），于是总是走 else 分支。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example12-warning.cpp -o a
//       预期产生警告：warning: suggest parentheses around assignment used as truth value [-Wparentheses]
//       （原文为"故意错误"示例，此处保留该错误以复现原文结论，勿"修复"）
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（输入 0）：
//   Enter 0 or 1: 0
//   You entered 1

#include <iostream>

int main()
{
    std::cout << "Enter 0 or 1: ";
    int x{};
    std::cin >> x;
    if (x = 0) // oops, we used an assignment here instead of a test for equality
        std::cout << "You entered 0\n";
    else
        std::cout << "You entered 1\n";

    return 0;
}
