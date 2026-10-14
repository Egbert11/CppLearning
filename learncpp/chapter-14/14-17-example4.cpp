// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：constexpr 聚合对象——把 p 声明为 constexpr 后，p.greater()
//           成为可用的常量表达式，可初始化 constexpr 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 4）---
struct Pair // Pair is an aggregate
{
    int m_x {};
    int m_y {};

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };        // now constexpr
    std::cout << p.greater() << '\n'; // p.greater() evaluates at runtime or compile-time

    constexpr int g { p.greater() };  // p.greater() must evaluate at compile-time
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 6
// 6
