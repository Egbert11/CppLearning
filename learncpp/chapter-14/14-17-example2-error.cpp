// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：聚合 Pair 的 greater() 是普通成员函数，不是 constexpr，
//           因此 p.greater() 不是常量表达式，无法初始化 constexpr 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：constexpr int g { p.greater() }; 处——调用非 constexpr 函数
//           （call to non-'constexpr' function 'int Pair::greater() const'）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
struct Pair
{
    int m_x {};
    int m_y {};

    int greater() const // note: not constexpr
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    Pair p { 5, 6 };                  // inputs are constexpr values
    std::cout << p.greater() << '\n'; // p.greater() evaluates at runtime

    constexpr int g { p.greater() };  // compile error: greater() not constexpr
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---
