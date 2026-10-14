// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：approximatelyEqualRel()——Knuth 的相对 epsilon 算法，并按原文测试。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。输出：true 然后 false
//   （近零时相对 epsilon 退化，第二种情形失败）
// ============================================================
#include <algorithm> // for std::max
#include <cmath>     // for std::abs
#include <iostream>

// --- 原文示例片段 ---
// Return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
// --- 原文示例片段结束 ---

int main()
{
    // --- 原文示例片段 ---
    // a is really close to 1.0, but has rounding errors
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps { 1e-8 };

    std::cout << std::boolalpha; // print true or false rather than 1 or 0

    std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';     // compare "almost 1.0" to 1.0 -> true
    std::cout << approximatelyEqualRel(a-1.0, 0.0, relEps) << '\n'; // compare "almost 0.0" to 0.0 -> false
    // --- 原文示例片段结束 ---

    return 0;
}
