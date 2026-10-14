// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：浮点减法意外——d1 与 d2 数学上都等于 0.01，却因舍入误差不相等。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。
//   d1 = 0.010000000000005116, d2 = 0.0099999999999997868 -> 输出 "d1 > d2"
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr double d1{ 100.0 - 99.99 }; // should equal 0.01 mathematically
    constexpr double d2{ 10.0 - 9.99 };   // should equal 0.01 mathematically

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
