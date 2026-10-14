// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：替代运算符关键字 and / or / not 与符号形式表达式完全相同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
//   原文倾向使用符号形式，本示例为清晰起见把结果存入 bool 变量。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // Original lesson used:
    //   std::cout << !a && (b || c);
    //   std::cout << not a and (b or c);

    bool a{ false };
    bool b{ true };
    bool c{ false };

    bool symbolic  { !a && (b || c) };       // using ! && ||
    bool keyword   { not a and (b or c) };   // identical using not / and / or

    std::cout << std::boolalpha;
    std::cout << "!a && (b || c) = " << symbolic << '\n';
    std::cout << "not a and (b or c) = " << keyword << '\n';
    std::cout << "identical: " << (symbolic == keyword) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
