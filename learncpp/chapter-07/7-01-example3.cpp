// 来源小节：7.1 Compound statements (blocks)
// 示例说明：默认情况下 if 只执行一条语句；用块可以让 if/else 各执行多条语句。
//           （对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
//
// 预期输出（输入 3）：
//   Enter an integer: 3
//   3 is a positive integer (or zero)
//   Double this number is 6
// 预期输出（输入 -4）：
//   Enter an integer: -4
//   -4 is a negative integer
//   The positive of this number is 4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // start of outer block
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value >= 0)
    { // start of nested block
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } // end of nested block
    else
    { // start of another nested block
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    } // end of another nested block

    return 0;
} // end of outer block
