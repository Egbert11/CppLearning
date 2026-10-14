// ============================================================
// 来源小节：6.7 Relational operators and floating point comparisons
// 示例说明：条件是布尔值，写 `if (b1)` / `if (!b1)` 比 `== true` / `== false` 更好。
// 原文链接：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    bool b1{ true };

    if (b1 == true) // not good: redundant
        std::cout << "b1 == true\n";
    if (b1)         // good: concise
        std::cout << "b1\n";

    if (b1 == false) // not good: redundant
        std::cout << "b1 == false\n";
    if (!b1)         // good: concise
        std::cout << "!b1\n";
    // --- 原文示例片段结束 ---

    return 0;
}
