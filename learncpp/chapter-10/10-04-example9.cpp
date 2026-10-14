// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：用 double 字面量初始化 float —— 合法（constexpr 且在范围内），即使
//           实际会丢精度。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example9.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    float f{ 1.23456789 }; // not a narrowing conversion, even though precision lost!
    // --- 原文示例片段结束 ---

    std::cout << f << '\n';

    return 0;
}
