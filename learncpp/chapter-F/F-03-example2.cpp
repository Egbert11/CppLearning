// 来源小节：F.3 Constexpr functions (part 3) and consteval
// 示例说明：用 std::is_constant_evaluated() 判断当前是否处于"常量求值语境"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/
//
// 预期输出（-O0）：
//   1 2
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       原文用未定义的 doSomething()/doSomethingElse() 做占位示意；
//       为使其可编译，此处补上定义：常量语境分支必须能编译期求值（故 constexpr 且无 I/O），
//       运行期分支用普通函数。
//       注意：b 在非必须常量表达式的语境中求值，-O0 时按运行期处理得到 2；
//             若开启 -O2，编译器可能改为编译期求值而得到 1（实现相关）。
#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

constexpr int doSomething()     { return 1; } // 常量语境分支：必须能编译期求值
int doSomethingElse()           { return 2; } // 运行期分支

constexpr int someFunction()
{
    // --- 原文示例片段 ---
    if (std::is_constant_evaluated()) // if evaluating in constant context
        return doSomething();
    else
        return doSomethingElse();
    // --- 原文示例片段结束 ---
}

int main()
{
    constexpr int a { someFunction() }; // constant context: uses doSomething() -> 1
    int b { someFunction() };           // runtime context (at -O0): uses doSomethingElse() -> 2

    std::cout << a << ' ' << b << '\n';

    return 0;
}
