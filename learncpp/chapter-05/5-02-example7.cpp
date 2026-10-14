// ============================================================
// 来源小节：5.2 Literals
// 示例说明：浮点字面量的标准计数法（带小数点），以及负数字面量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double d { -1.23 };    // the literal can be negative
    double why { 0. };     // syntactically acceptable, but avoid this because it's hard to see the decimal point (prefer 0.0)
    // --- 原文示例片段结束 ---

    std::cout << pi << '\n' << d << '\n' << why << '\n';

    return 0;
}
