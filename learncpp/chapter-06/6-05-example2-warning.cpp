// ============================================================
// 来源小节：6.5 The comma operator
// 示例说明：逗号优先级最低，导致两种写法的含义截然不同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-comma-operator/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
// 备注：本节代码为按原文描述忠实重建。
//   注意：`z = a, b;` 等价于 `(z = a), b;`，b 被求值后丢弃，可能触发 -Wunused-value。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int z{ 0 };
    int a{ 10 };
    int b{ 20 };

    z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
    std::cout << "z = (a, b);  -> z = " << z << '\n'; // z = 20

    z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.
    std::cout << "z = a, b;    -> z = " << z << '\n'; // z = 10
    // --- 原文示例片段结束 ---

    return 0;
}
