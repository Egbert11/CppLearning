// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：哪些变量“可用于常量表达式”。
//           const 整型且初始化式为常量表达式 -> 可以；
//           非 const、或 const 非整型（如 double）-> 不可以。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] const int a { 5 };       // a is usable in constant expressions
    [[maybe_unused]] const int b { a };       // b is usable in constant expressions (a is a constant expression)
    [[maybe_unused]] const long c { a + 2 };  // c is usable in constant expressions (a + 2 is a constant expression)

    [[maybe_unused]] int d { 5 };             // d is not usable in constant expressions (d is non-const)
    [[maybe_unused]] const int e { d };       // e is not usable in constant expressions (initializer is not a constant expression)
    [[maybe_unused]] const double f { 1.2 };  // f is not usable in constant expressions (const non-integral)
    // --- 原文示例片段结束 ---

    return 0;
}
