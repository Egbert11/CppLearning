// ============================================================
// 来源小节：14.17 Constexpr aggregates and classes
// 示例说明：constexpr 函数在编译期求值时只能调用具备编译期求值能力的函数；
//           对类类型而言，创建的对象必须用 constexpr 构造函数，调用的成员
//           函数也必须是 constexpr。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Pair
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y): m_x { x }, m_y { y } {}

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

// --- 原文示例片段（原 Example 7）---
constexpr int init()
{
    Pair p { 5, 6 };    // requires constructor to be constexpr when evaluated at compile-time
    return p.greater(); // requires greater() to be constexpr when evaluated at compile-time
}

int main()
{
    constexpr int g { init() }; // init() evaluated in compile-time context
    std::cout << g << '\n';

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 6
