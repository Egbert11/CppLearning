// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：普通 Pair（两个 int 成员）配合按值传递的 max(Pair)——非模板做法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 3）---
struct Pair
{
    int first{};
    int second{};
};

constexpr int max(Pair p) // pass by value because Pair is small
{
    return (p.first < p.second) ? p.second : p.first;
}

int main()
{
    Pair p1{ 5, 6 };
    std::cout << max(p1) << '\n';

    return 0;
}

// 预期输出：
// 6
