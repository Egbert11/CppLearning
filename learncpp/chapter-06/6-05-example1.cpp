// ============================================================
// 来源小节：6.5 The comma operator
// 示例说明：在 std::cout 中使用逗号运算符，同时自增 x、y，表达式结果为右操作数的值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-comma-operator/
// 备注：本节代码为按原文描述忠实重建。输出：3
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand
    // --- 原文示例片段结束 ---

    return 0;
}
