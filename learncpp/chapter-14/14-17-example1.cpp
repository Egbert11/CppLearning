// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：constexpr 自由函数既可在编译期也可在运行期求值；用于初始化
//           constexpr 变量时必须在编译期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greater(5, 6) << '\n'; // greater(5, 6) may be evaluated at compile-time or runtime

    constexpr int g { greater(5, 6) };  // greater(5, 6) must be evaluated at compile-time
    std::cout << g << '\n';             // prints 6

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 6
// 6
