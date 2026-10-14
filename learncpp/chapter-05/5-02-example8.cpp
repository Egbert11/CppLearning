// ============================================================
// 来源小节：5.2 Literals
// 示例说明：浮点字面量的科学计数法（e 表示 10 的幂）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    double avogadro { 6.02e23 };     // 6.02 x 10^23 is a double literal in scientific notation
    double protonCharge { 1.6e-19 }; // charge on a proton is 1.6 x 10^-19
    // --- 原文示例片段结束 ---

    std::cout << avogadro << '\n' << protonCharge << '\n';

    return 0;
}
