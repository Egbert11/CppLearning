// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：C++14/17/20 变通——用自制 constexpr 的 constAbs() 函数模板替代 std::abs，
//           使近似比较函数能在常量表达式中使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建（C++14/17/20 version）。
// ============================================================
#include <algorithm> // for std::max
#include <cmath>     // (for runtime std::abs, if desired)
#include <iostream>

// --- 原文示例片段（C++14/17/20 version）---
// Our own constexpr implementation of std::abs (for use in C++14/17/20)
// constAbs() can be called like a normal function, but can handle different types of values (e.g. int, double, etc...)
template <typename T>
constexpr T constAbs(T x)
{
    return (x < 0 ? -x : x);
}

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (constAbs(a - b) <= (std::max(constAbs(a), constAbs(b)) * relEpsilon));
}

constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    if (constAbs(a - b) <= absEpsilon)
        return true;

    return approximatelyEqualRel(a, b, relEpsilon);
}
// --- 原文示例片段结束 ---

int main()
{
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    // Compiles and works even before C++23 (C++14+)
    constexpr bool same { approximatelyEqualAbsRel(a, 1.0, absEps, relEps) };

    std::cout << std::boolalpha;
    std::cout << same << '\n';                                               // true
    std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, absEps, relEps) << '\n'; // true

    return 0;
}
