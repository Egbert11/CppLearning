// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：把构造函数标记为 constexpr，该类就能在编译期创建对象，
//           行为与聚合版本一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 6）---
class Pair
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y): m_x { x }, m_y { y } {} // now constexpr

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };
    std::cout << p.greater() << '\n';

    constexpr int g { p.greater() };
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 6
// 6
