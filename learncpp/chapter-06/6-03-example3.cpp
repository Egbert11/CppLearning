// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：用 std::pow() 计算 3 的 4 次方。参数与返回值都是 double。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <cmath>     // for std::pow
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
    std::cout << x << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
