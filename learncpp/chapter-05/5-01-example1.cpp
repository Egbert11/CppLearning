// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：演示非常量（non-constant）变量可以被重新赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 4 };            // x is a non-constant variable
    std::cout << x << '\n';

    x = 5;                  // ok: we can change the value of a non-constant variable
    std::cout << x << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
