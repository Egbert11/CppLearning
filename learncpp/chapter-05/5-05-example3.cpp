// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：因为变量是 constexpr，其初始化式必须是可在编译期
//           求值的常量表达式；否则编译器报错并停止编译。
//           可编译示例用常量表达式 5 + 5 代替原文的占位符 expr。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // constexpr int x { expr }; // Because variable x is constexpr, expr must be evaluatable at compile-time
    // --- 原文示例片段结束 ---

    // 用一个真正的常量表达式来满足上面的要求：
    constexpr int x { 5 + 5 };
    std::cout << x << '\n';

    return 0;
}
