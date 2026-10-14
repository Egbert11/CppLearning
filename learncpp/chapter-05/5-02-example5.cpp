// ============================================================
// 来源小节：5.2 Literals
// 示例说明：float 用未加后缀的 double 字面量初始化会告警，
//           以及两种可接受的修复方式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（示例 5：会触发告警）---
    float f { 4.1 }; // warning: 4.1 is a double literal, not a float literal
    // --- 原文示例片段结束 ---
    std::cout << f << '\n';

    // --- 原文示例片段（示例 6：两种修复方式）---
    float g { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
    double d { 4.1 }; // change variable to type double so it matches the literal type double
    // --- 原文示例片段结束 ---
    std::cout << g << '\n' << d << '\n';

    return 0;
}
