// 来源小节：F.4 Constexpr functions (part 4)
// 示例说明：用 bool 形参在 constexpr 函数内分支选择 constexpr / 非 constexpr 实现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/
//
// 预期输出（-O0）：
//   1 2
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       合法性前提：调用非 constexpr 函数的那个分支，在常量表达式中永远不会被走到
//       （即不要在常量表达式里调用 someFunction(false)）。
//       原文的 someConstexprFcn()/someNonConstexprFcn() 为占位名，此处补上定义以便编译运行。
#include <iostream>

constexpr int someConstexprFcn()    { return 1; } // 原文占位函数，此处补定义
int someNonConstexprFcn()           { return 2; } // 原文占位函数，此处补定义

constexpr int someFunction(bool b)
{
    // --- 原文示例片段 ---
    if (b)
        return someConstexprFcn();
    else
        return someNonConstexprFcn(); // legal as long as someFunction(false) is never called in a constant expression
    // --- 原文示例片段结束 ---
}

int main()
{
    constexpr int a { someFunction(true) };  // constant context -> 1
    int b { someFunction(false) };           // runtime context (at -O0) -> 2

    std::cout << a << ' ' << b << '\n';

    return 0;
}
