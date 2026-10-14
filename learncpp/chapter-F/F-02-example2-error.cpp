// 来源小节：F.2 Constexpr functions (part 2)
// 示例说明：constexpr 函数里调用了非 constexpr 函数 —— 运行期可用，但放进常量表达式就报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/
//
// 预期错误：foo() 内部调用了非 constexpr 的 getValue()，无法在编译期求值，
//   因此 constexpr int y { foo(5) }; 编译失败。g++ 报错类似：
//   error: call to non-'constexpr' function 'int getValue(int)'
//   error: 'constexpr' variable 'y' is not a constant expression
//
// 说明：本文件为按原文描述重建，故意保留编译错误，请勿修复。
//       本文件预期编译失败。
#include <iostream>

int getValue(int x) // not constexpr
{
    return x;
}

constexpr int foo(int x)
{
    // Prior to C++23 (P2448R1), a constexpr function had to be evaluatable at
    // compile-time for at least one set of arguments, hence this branch.
    if (x < 0)
        return 0;

    return getValue(x); // call to non-constexpr function here
}

int main()
{
    int x { foo(5) }; // okay: foo() is evaluated at runtime here

    constexpr int y { foo(5) }; // compile error: foo() can't be evaluated at compile-time

    std::cout << x << '\n';

    return 0;
}
