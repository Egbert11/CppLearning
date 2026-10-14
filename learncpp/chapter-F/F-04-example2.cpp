// 来源小节：F.4 Constexpr functions (part 4)
// 示例说明：把非 constexpr 的形参 b 传进 constexpr 调用 goo(b)，若 foo() 在编译期求值则 goo(b) 也能编译期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/
//
// 预期输出：
//   5
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
#include <iostream>

constexpr int goo(int c) // goo() is now constexpr
{
    return c;
}

constexpr int foo(int b) // b is not a constant expression within foo()
{
    // --- 原文示例片段 ---
    return goo(b);       // if foo() is resolved at compile-time, then `goo(b)` can also be resolved at compile-time
    // --- 原文示例片段结束 ---
}

int main()
{
    std::cout << foo(5);

    return 0;
}
