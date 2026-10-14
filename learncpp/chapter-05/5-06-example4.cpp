// 来源小节：5.6 Constexpr variables
// 示例说明：非整型的 constexpr——constexpr double 可用于常量表达式，而 const double 通常不行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 预期输出：
//   1.44

#include <iostream>

int main()
{
    constexpr double d { 1.2 }; // d can be used in constant expressions!
    const double e { 1.2 };     // e is typically NOT usable in constant expressions

    constexpr double area { d * d }; // ok: d is a compile-time constant

    std::cout << area << '\n';

    (void)e; // 仅为消除“未使用变量”告警

    return 0;
}
