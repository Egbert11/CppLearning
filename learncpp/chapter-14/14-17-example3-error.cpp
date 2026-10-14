// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：把 greater() 标记为 constexpr 还不够——对象 p 本身也必须是
//           constexpr，否则 p.greater() 仍不是常量表达式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：constexpr int g { p.greater() }; 处——p 不是常量表达式
//           （'p' is not usable in a constant expression）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 3）---
struct Pair
{
    int m_x {};
    int m_y {};

    constexpr int greater() const // can evaluate at either compile-time or runtime
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    Pair p { 5, 6 };
    std::cout << p.greater() << '\n'; // okay: p.greater() evaluates at runtime

    constexpr int g { p.greater() };  // compile error: p not constexpr
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---
