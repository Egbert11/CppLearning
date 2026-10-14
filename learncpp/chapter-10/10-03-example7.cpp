// 来源小节：10.3 Numeric conversions
// 示例说明：同族窄化（大 -> 小）在取值装得下时可行；整数 -> 浮点（10 -> 10.0f）；
//           浮点 -> 整数丢掉小数部分（3.5 -> 3）。（对应原文示例 15、17、18）
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example7.cpp -o a
// 预期输出：
//   2
//   0.1234
//   10
//   3
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（int -> short，取值装得下） ---
    int i{ 2 };
    short s = i; // convert from int to short
    std::cout << s << '\n';
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（double -> float，取值装得下） ---
    double d{ 0.1234 };
    float f = d;
    std::cout << f << '\n';
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（int -> float） ---
    int i2{ 10 };
    float f2 = i2;
    std::cout << f2 << '\n';
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（浮点 -> 整数，丢小数） ---
    int i3 = 3.5;
    std::cout << i3 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
