// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：为 int 和 double 各写一个重载 max，演示模板要消除的代码重复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
int max(int x, int y)
{
    return (x < y) ? y : x;
}

double max(double x, double y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(1, 2) << '\n';     // calls max(int, int)
    std::cout << max(1.5, 2.5) << '\n'; // calls max(double, double)

    return 0;
}

// 预期输出：
// 2
// 2.5
