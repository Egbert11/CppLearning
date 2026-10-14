// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：在流输出中忘记给条件运算符加括号——operator<< 先结合，打印 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
// 备注：本节代码为按原文描述忠实重建。输出：0 （而非预期的 non-negative）
//       预期产生 -Wunused-value 警告（三元运算符的两个分支无效果）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 2 };

    // This is parsed as: (std::cout << (x < 0)) ? "negative" : "non-negative";
    // operator<< binds before operator?:, so it prints the bool value 0,
    // then the ternary result is thrown away.
    std::cout << (x < 0) ? "negative" : "non-negative";
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
