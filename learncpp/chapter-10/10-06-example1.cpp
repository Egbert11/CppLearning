// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：整数除法陷阱——10 / 4 先做整数除法得 2，再转成 2.0；用 double 字面量
//           才能得到 2.5。（对应原文示例 1~3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example1.cpp -o a
// 预期输出：
//   2
//   2.5
//   2
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（示例 1） ---
    double d = 10 / 4; // does integer division, initializes d with value 2.0
    // --- 原文示例片段结束 ---
    std::cout << d << '\n'; // 2

    // --- 原文示例片段（示例 2） ---
    double d2 = 10.0 / 4.0; // does floating point division, initializes d with value 2.5
    // --- 原文示例片段结束 ---
    std::cout << d2 << '\n'; // 2.5

    // --- 原文示例片段（示例 3） ---
    int x{ 10 };
    int y{ 4 };
    double d3 = x / y; // does integer division, initializes d with value 2.0
    // --- 原文示例片段结束 ---
    std::cout << d3 << '\n'; // 2

    return 0;
}
