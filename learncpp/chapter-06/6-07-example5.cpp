// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：approximatelyEqualAbs()——朴素的绝对 epsilon 版本。
//           固定 epsilon 在量级差别很大时表现不佳。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <cmath>     // for std::abs()
#include <iostream>

// --- 原文示例片段 ---
// Return true if the difference between a and b is less than absEpsilon
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // Check if the difference between a and b is less than or equal to the epsilon
    return std::abs(a - b) <= absEpsilon;
}
// --- 原文示例片段结束 ---

int main()
{
    constexpr double absEpsilon { 1e-5 }; // 0.00001

    std::cout << std::boolalpha;
    // 1.0 附近：合理
    std::cout << approximatelyEqualAbs(1.0, 1.00001, absEpsilon) << '\n'; // true
    std::cout << approximatelyEqualAbs(1.0, 1.0001, absEpsilon) << '\n';  // false
    // 0.0 附近：过大的 epsilon 把量级差两级的数也算相等（糟糕）
    std::cout << approximatelyEqualAbs(0.0000001, 0.00001, absEpsilon) << '\n'; // true (bad)
    // 大数附近：过小的 epsilon 把几乎无法区分的数算不同（糟糕）
    std::cout << approximatelyEqualAbs(10000.0, 10000.0001, absEpsilon) << '\n'; // false (bad)

    return 0;
}
