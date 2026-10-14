// 来源小节：F.2 Constexpr functions (part 2)
// 示例说明：constexpr 函数用在"非必须常量表达式"的语境里，可能编译期求值也可能运行期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/
//
// 预期输出：
//   5
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
#include <iostream>

constexpr int getValue(int x)
{
    return x;
}

int main()
{
    // --- 原文示例片段 ---
    // x is not constexpr, so the initializer is not required to be a constant
    // expression; the compiler may evaluate getValue(5) at compile-time or runtime.
    int x { getValue(5) }; // may evaluate at runtime or compile-time

    std::cout << x << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
