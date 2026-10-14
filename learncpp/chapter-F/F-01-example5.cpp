// 来源小节：F.1 Constexpr functions
// 示例说明：用非 constexpr 的实参调用 constexpr 函数，函数在运行时求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions/
//
// 预期输出：
//   6 is greater!
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 }; // not constexpr
    int y{ 6 }; // not constexpr

    std::cout << greater(x, y) << " is greater!\n"; // will be evaluated at runtime
    // --- 原文示例片段结束 ---

    return 0;
}
