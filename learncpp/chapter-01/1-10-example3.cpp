// 来源小节：1.10 Introduction to expressions
// 示例说明：进阶——三个带副作用的表达式，说明各自求值为 x、x、std::cout。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
//
// 编译：g++ -std=c++20 -Wall 1-10-example3.cpp -o example3

#include <iostream>

int main()
{
    int x {};

    // --- 原文示例片段（带副作用的表达式）---
    x = 5;          // assigns 5 to x, evaluates to x
    x = 2 + 3;      // assigns 5 to x, evaluates to x
    std::cout << x; // prints x, evaluates to std::cout
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
