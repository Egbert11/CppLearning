// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：用 if-else 给 max 赋值，再改写成条件运算符一行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int x{ 5 };
    constexpr int y{ 7 };

    int max{};
    if (x > y)
        max = x;
    else
        max = y;
    std::cout << "max (if-else) = " << max << '\n';

    // 改写成条件运算符
    max = ((x > y) ? x : y);
    std::cout << "max (?:) = " << max << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
