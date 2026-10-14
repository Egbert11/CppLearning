// ============================================================
// 来源小节：6.1 Operator precedence and associativity
// 示例说明：测验——给下列表达式补全括号，使其分组一目了然。
// 原文链接：https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // 题意：给下面每个表达式按优先级/结合性补全括号

    int a { 1 }, b { 0 }, c { 1 }, d { 1 };
    int x { 0 }, y { 1 }, z { 2 };

    // a) x = 3 + 4 + 5;
    //    -> x = ((3 + 4) + 5);   // 加法左结合
    x = ((3 + 4) + 5);

    // b) x = y = z;
    //    -> x = (y = z);         // 赋值右结合
    x = (y = z);

    // c) z *= ++y + 5;
    //    -> z *= ((++y) + 5);    // 一元 ++ 优先级高于 +
    z *= ((++y) + 5);

    // d) a || b && c || d;
    //    -> (a || (b && c)) || d; // && 优先级高于 ||
    bool result { (a || (b && c)) || d };
    // --- 原文示例片段结束 ---

    std::cout << std::boolalpha;
    std::cout << "x = " << x << '\n';
    std::cout << "z = " << z << '\n';
    std::cout << "(a || b && c || d) = " << result << '\n';

    return 0;
}
