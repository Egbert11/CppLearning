// 来源小节：1.10 Introduction to expressions
// 示例说明：用字面量、表达式、变量、函数返回值分别初始化 a–e（结果为 2、5、10、5、5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
//
// 编译：g++ -std=c++20 -Wall 1-10-example1.cpp -o example1

#include <iostream>

int five()
{
    return 5;
}

int main()
{
    // --- 原文示例片段 ---
    int a{ 2 };             // initialize with a literal
    int b{ 2 + 3 };         // initialize with an expression
    int c{ (2 * 3) + 4 };   // initialize with an expression
    int d{ b };             // initialize with a variable
    int e{ five() };        // initialize with a function return value
    // --- 原文示例片段结束 ---

    std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
    return 0;
}
