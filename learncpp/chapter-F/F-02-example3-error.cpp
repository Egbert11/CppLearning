// 来源小节：F.2 Constexpr functions (part 2)
// 示例说明：constexpr 函数的形参本身不是 constexpr —— 不能用作其内部 constexpr 变量的初值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/
//
// 预期错误：形参 b 不是 constexpr，因此
//   constexpr int b2 { b };  // 编译错误
//   return goo(b);           // 编译错误（b 不能用于常量表达式）
// g++ 报错类似：
//   error: 'b' is not a constant expression
//
// 说明：本文件为按原文描述重建，故意保留编译错误，请勿修复。
//       本文件预期编译失败。
#include <iostream>

consteval int goo(int c)
{
    return c; // c is not constexpr
}

constexpr int foo(int b) // b is not constexpr
{
    constexpr int b2 { b }; // compile error: b is not a constant expression
    return goo(b);          // compile error: b is not constexpr, can't be used in a constant expression
}

int main()
{
    constexpr int a { 5 };

    // foo() is constexpr, and the argument (a) is a constant expression,
    // so foo(a) can be evaluated at compile-time.
    // Note: the parameter b inside foo() is still NOT constexpr.
    std::cout << foo(a);

    return 0;
}
