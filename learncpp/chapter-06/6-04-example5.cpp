// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：副作用的三个例子——赋值、自增、operator<< 都会在返回值之外改变状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    x = 6;              // assignment: changes the value of x to 6 (side effect)
    ++x;                // operator++: increments x to 7 (side effect)
    std::cout << x;     // operator<<: modifies the state of the console (side effect)
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
