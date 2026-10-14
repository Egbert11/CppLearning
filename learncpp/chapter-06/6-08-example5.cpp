// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：逻辑与——范围检查 `value > 10 && value < 20`，以及链式 &&。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter a number: ";
    int value{};
    std::cin >> value;

    if (value > 10 && value < 20)
        std::cout << "Your value is between 10 and 20\n";
    else
        std::cout << "Your value is not between 10 and 20\n";

    // Chained ANDs
    if (value > 10 && value < 20 && value != 16)
        std::cout << "Your value is between 10 and 20 and not 16\n";
    // --- 原文示例片段结束 ---

    return 0;
}
