// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：加括号修正——`!(x > y)` 先比较再取反，得到正确结论。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int y{ 7 };

    if (!(x > y))
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
