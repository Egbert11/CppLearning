// 来源小节：F.4 Constexpr functions (part 4)
// 示例说明：根据是否处于常量求值语境，选择调用 constexpr 或非 constexpr 的兄弟函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/
//
// 预期输出（-O0）：
//   1 2
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       原文的 someConstexprFcn()/someNonConstexprFcn() 为占位名，此处补上定义以便编译运行。
//       b 在非必须常量表达式语境中求值，-O0 时按运行期处理得到 2；
//       若开启 -O2，编译器可能改为编译期求值而得到 1（实现相关）。
#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

constexpr int someConstexprFcn()    { return 1; } // 原文占位函数，此处补定义
int someNonConstexprFcn()           { return 2; } // 原文占位函数，此处补定义

constexpr int someFunction()
{
    // --- 原文示例片段 ---
    if (std::is_constant_evaluated()) // if evaluating in constant context
        return someConstexprFcn();
    else
        return someNonConstexprFcn();
    // --- 原文示例片段结束 ---
}

int main()
{
    constexpr int a { someFunction() }; // constant context -> 1
    int b { someFunction() };           // runtime context (at -O0) -> 2

    std::cout << a << ' ' << b << '\n';

    return 0;
}
