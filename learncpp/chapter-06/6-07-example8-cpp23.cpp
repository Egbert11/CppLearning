// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：C++23 的 constexpr 版本。std::abs 从 C++23 起是 constexpr，
//           故这两个近似比较函数可在常量表达式中使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// !! -cpp23：需要 g++ -std=c++23 编译。
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <algorithm> // for std::max
#include <cmath>     // for std::abs (constexpr in C++23)
#include <iostream>

// --- 原文示例片段（C++23 version）---
// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than absEpsilon,
// or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}
// --- 原文示例片段结束 ---

int main()
{
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    // Used in a constant expression: only works in C++23+
    constexpr bool same { approximatelyEqualAbsRel(a, 1.0, absEps, relEps) };

    std::cout << std::boolalpha;
    std::cout << same << '\n';
    std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, absEps, relEps) << '\n';

    return 0;
}
