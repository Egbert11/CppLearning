// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：前缀自增。x 先变为 6，表达式求值为 6，故 y 得 6。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// 备注：本节代码为按原文描述忠实重建。输出：6 6
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int y { ++x }; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
