// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：当不使用表达式返回值时，前缀与后缀行为相同（都是把 x 加 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 0 };
    ++x; // increments x to 1
    x++; // increments x to 2

    std::cout << x << '\n'; // prints 2
    // --- 原文示例片段结束 ---

    return 0;
}
