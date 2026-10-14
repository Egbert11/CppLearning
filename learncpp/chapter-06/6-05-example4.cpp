// ============================================================
// 来源小节：6.5 The comma operator
// 示例说明：逗号作为“分隔符”而非逗号运算符的三种场景。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-comma-operator/
// 备注：本节代码为按原文描述忠实重建（为可编译补全 add 函数与调用）。
// ============================================================
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

// --- 原文示例片段 ---
void foo(int x, int y) // Separator comma used to separate parameters in function definition
{
    std::cout << add(x, y) << '\n'; // Separator comma used to separate arguments in function call
    constexpr int z{ 3 }, w{ 5 };   // Separator comma used to separate multiple variables being defined on the same line (don't do this)
    std::cout << z << ' ' << w << '\n';
}
// --- 原文示例片段结束 ---

int main()
{
    foo(1, 2);
    return 0;
}
