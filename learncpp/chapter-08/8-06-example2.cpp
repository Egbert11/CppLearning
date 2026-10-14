// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：用 C++17 的 [[fallthrough]] 属性标记"有意的贯穿"，避免编译器/分析工具报警。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   2
//   3

#include <iostream>

int main()
{
    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        break;
    }

    return 0;
}
