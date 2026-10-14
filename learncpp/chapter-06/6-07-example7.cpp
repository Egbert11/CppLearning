// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：approximatelyEqualAbsRel()——先绝对比较（处理近零），否则回退到 Knuth 算法。
//           同时运行相对版本与组合版本，展示组合版能正确处理近零输入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。输出：true / false / true / true
// ============================================================
#include <algorithm> // for std::max
#include <cmath>     // for std::abs
#include <iostream>

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// --- 原文示例片段 ---
// Return true if the difference between a and b is less than absEpsilon,
// or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}
// --- 原文示例片段结束 ---

int main()
{
    // a is really close to 1.0, but has rounding errors
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    std::cout << std::boolalpha; // print true or false rather than 1 or 0

    std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';      // compare "almost 1.0" to 1.0     -> true
    std::cout << approximatelyEqualRel(a-1.0, 0.0, relEps) << '\n';  // compare "almost 0.0" to 0.0     -> false

    std::cout << approximatelyEqualAbsRel(a, 1.0, absEps, relEps) << '\n';     // compare "almost 1.0" to 1.0 -> true
    std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, absEps, relEps) << '\n'; // compare "almost 0.0" to 0.0 -> true

    return 0;
}
