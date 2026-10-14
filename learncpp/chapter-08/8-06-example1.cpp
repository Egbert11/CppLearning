// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：fallthrough（贯穿）——没有 break/return，执行会从匹配的 case 一路"溢出"到后续 case。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   2
//   3
//   4
//   5

#include <iostream>

int main()
{
    switch (2)
    {
    case 1: // Does not match
        std::cout << 1 << '\n'; // Skipped
    case 2: // Match!
        std::cout << 2 << '\n'; // Execution begins here
    case 3:
        std::cout << 3 << '\n'; // This is also executed
    case 4:
        std::cout << 4 << '\n'; // This is also executed
    default:
        std::cout << 5 << '\n'; // This is also executed
    }

    return 0;
}
