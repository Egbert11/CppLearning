// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：短路求值的副作用——`x == 1 && ++y == 2`，当 x 不等于 1 时 ++y 被跳过。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
//   本例中 x = 0，故 ++y 不执行，y 保持为 2。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 0 };
    int y{ 2 };

    std::cout << "before: x = " << x << ", y = " << y << '\n';

    if (x == 1 && ++y == 2) // x is not 1, so ++y is never evaluated (short circuit)
        std::cout << "condition is true\n";
    else
        std::cout << "condition is false\n";

    std::cout << "after:  x = " << x << ", y = " << y << '\n'; // y is still 2
    // --- 原文示例片段结束 ---

    return 0;
}
