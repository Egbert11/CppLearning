// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：非聚合类（私有成员 + 用户构造函数）——构造函数不是 constexpr，
//           该类不是字面类型（literal type），故无法创建 constexpr 对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：constexpr Pair p { 5, 6 }; 处——p 不是字面类型
//           （the type 'Pair' is not a literal type / not usable in a constant expression）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 5）---
class Pair // Pair is no longer an aggregate
{
private:
    int m_x {};
    int m_y {};

public:
    Pair(int x, int y): m_x { x }, m_y { y } {} // note: constructor is not constexpr

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };       // compile error: p is not a literal type
    std::cout << p.greater() << '\n';

    constexpr int g { p.greater() };
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---
