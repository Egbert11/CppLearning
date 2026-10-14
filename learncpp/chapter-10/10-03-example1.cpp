// 来源小节：10.3 Numeric conversions
// 示例说明：数值转换的五种基本情形：整型→整型、浮点→浮点、浮点→整型、整型→浮点、
//           整数/浮点→bool（分别对应原文示例 1~5，均用拷贝初始化）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（整型 -> 整型，不含提升） ---
    short s = 3;          // convert int to short
    long l = 3;           // convert int to long
    char ch = s;          // convert short to char
    unsigned int u = 3;   // convert int to unsigned int
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（浮点 -> 浮点，不含提升） ---
    float f = 3.0;        // convert double to float
    long double ld = 3.0; // convert double to long double
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（浮点 -> 整型） ---
    int i = 3.5;          // convert double to int
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（整型 -> 浮点） ---
    double d = 3;         // convert int to double
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（整数/浮点 -> bool） ---
    bool b1 = 3;          // convert int to bool
    bool b2 = 3.0;        // convert double to bool
    // --- 原文示例片段结束 ---

    std::cout << s << ' ' << l << ' ' << static_cast<int>(ch) << ' ' << u << '\n';
    std::cout << f << ' ' << static_cast<double>(ld) << '\n';
    std::cout << i << ' ' << d << '\n';
    std::cout << std::boolalpha << b1 << ' ' << b2 << '\n';

    return 0;
}
