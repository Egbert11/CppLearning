// 来源小节：8.2 If statements and blocks
// 示例说明：坏实践演示——误导性缩进。else 只能关联一条语句，因此缩进看起来像在
//           else 分支里的 "Too bad!" 实际上总是执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example2-broken.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（输入 180）：
//   You are tall enough to ride.
//   Too bad!

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
        std::cout << "You are tall enough to ride.\n";
    else
        std::cout << "You are not tall enough to ride.\n";
        std::cout << "Too bad!\n"; // 缩进具有误导性：这一行不在 else 分支里，总是执行

    return 0;
}
