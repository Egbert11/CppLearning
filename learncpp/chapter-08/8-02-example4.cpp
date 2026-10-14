// 来源小节：8.2 If statements and blocks
// 示例说明：用块（block / 复合语句）修正示例 2——给 else 加花括号，使两条语句都成为条件语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example4.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   输入 180 -> You are tall enough to ride.
//   输入 130 -> You are not tall enough to ride.
//               Too bad!

#include <iostream>

namespace constants
{
    constexpr int minRideHeightCM { 140 };
}

int main()
{
    std::cout << "Enter your height (in cm): ";
    int x{};
    std::cin >> x;

    if (x >= constants::minRideHeightCM)
    {
        std::cout << "You are tall enough to ride.\n";
    }
    else
    { // 注意这里的花括号
        std::cout << "You are not tall enough to ride.\n";
        std::cout << "Too bad!\n";
    } // 花括号把这两条语句变成了一条复合语句

    return 0;
}
