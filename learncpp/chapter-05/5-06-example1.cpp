// 来源小节：5.6 Constexpr variables
// 示例说明：判断 const 变量是否为常量表达式的“清晰情形”。
//           b 的初始化器是变量 a（非常量表达式），c 的初始化器是字面量 5（常量表达式）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 预期输出：
//   5 5 5

#include <iostream>

int main()
{
    int a { 5 };            // non-const
    const int b { a };      // NOT a constant expression (b's initializer is not a constant expression, since a is non-const)
    const int c { 5 };      // this IS a constant expression (c's initializer is a constant expression)

    std::cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}
