// 来源小节：8.4 Constexpr if statements
// 示例说明：用 if constexpr 重写示例 1——条件在编译期求值，编译器丢弃永远不会执行的分支。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/
//
// 编译：g++ -std=c++20 -Wall 8-04-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   Gravity is normal.

#include <iostream>

int main()
{
    constexpr double gravity{ 9.8 };

    if constexpr (gravity == 9.8) // now using constexpr if
        std::cout << "Gravity is normal.\n";
    else
        std::cout << "We are not on Earth.\n";

    return 0;
}
