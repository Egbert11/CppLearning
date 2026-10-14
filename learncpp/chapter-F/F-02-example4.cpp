// 来源小节：F.2 Constexpr functions (part 2)
// 示例说明：constexpr 函数可以在定义之前被另一个 constexpr 函数调用（前向声明的互递归场景）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/
//
// 预期输出：
//   5
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       For advanced readers（CWG2166）：只要 constexpr 函数的完整定义出现在
//       "最终导致该调用的最外层求值" 之前即可，因此允许这种相互引用。
#include <iostream>

constexpr int foo(int); // forward declaration

constexpr int goo(int c)
{
    return foo(c); // note that foo is not defined yet
}

constexpr int foo(int b)
{
    return b;
}

int main()
{
    // --- 原文示例片段 ---
    constexpr int a{ goo(5) }; // outermost invocation; foo is defined above this point

    std::cout << a << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
