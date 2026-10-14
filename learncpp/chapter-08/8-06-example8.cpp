// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：最安全的做法——在 case 下用显式块定义并初始化变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example8.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   4

#include <iostream>

int main()
{
    switch (1)
    {
    case 1:
    { // note addition of explicit block here
        int x{ 4 }; // okay, variables can be initialized inside a block inside a case
        std::cout << x << '\n';
        break;
    }

    default:
        std::cout << "default case\n";
        break;
    }

    return 0;
}
