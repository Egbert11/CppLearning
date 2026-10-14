// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：后缀自增。x 变为 6，而一份原值 5 的副本被求值并赋给 y。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// 备注：本节代码为按原文描述忠实重建。输出：6 5
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int y { x++ }; // x is incremented to 6, a copy of the value 5 is evaluated and assigned to y

    std::cout << x << ' ' << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
