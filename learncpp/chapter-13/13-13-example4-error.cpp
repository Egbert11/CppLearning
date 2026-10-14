// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：两个 Pair 类型定义不可重载；仅返回类型不同的 max 重载也非法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 预期错误：
//   1) redefinition of 'struct Pair'（第二次定义 Pair）
//   2) 'double max(Pair)' cannot be overloaded with 'int max(Pair)'
//      （只有返回类型不同，无法重载）
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败，用于演示上述两条规则，请勿修复。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 4）---
struct Pair
{
    int first{};
    int second{};
};

struct Pair // compile error: erroneous redefinition of Pair
{
    double first{};
    double second{};
};

constexpr int max(Pair p)
{
    return (p.first < p.second) ? p.second : p.first;
}

constexpr double max(Pair p) // compile error: overloaded function differs only by return type
{
    return (p.first < p.second) ? p.second : p.first;
}

int main()
{
    Pair p1{ 5, 6 };
    std::cout << max(p1) << '\n';

    return 0;
}
