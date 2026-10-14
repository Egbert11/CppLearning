// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：逻辑或——`value == 0 || value == 1`；并演示错误写法 `value == 0 || 1`（恒真）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter a single digit integer: ";
    int value{};
    std::cin >> value;

    if (value == 0 || value == 1) // correct: if value is 0, or if value is 1
        std::cout << "You picked 0 or 1\n";
    else
        std::cout << "You did not pick 0 or 1\n";

    // Warning: this is incorrect! `1` converts to `true`, so the condition is always true.
    // if (value == 0 || 1)
    //     ...

    // Chained ORs
    if (value == 0 || value == 1 || value == 2 || value == 3)
        std::cout << "You picked a small number\n";
    // --- 原文示例片段结束 ---

    return 0;
}
