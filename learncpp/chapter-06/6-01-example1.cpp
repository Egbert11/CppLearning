// ============================================================
// 来源小节：6.1 Operator precedence and associativity
// 示例说明：演示单赋值表达式中，右操作数的括号可有可无。
//           多赋值/复合表达式加括号可读性更好。
// 原文链接：https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int y { 3 };
    int z { 5 };
    bool w { true };

    // 单赋值表达式的右操作数不需要括号
    int x { y + z + 1 };            // no parentheses needed: x = y + z + 1;
    bool cond { (y || z) && w };    // (y || z) && w  // 括号只是可读性增强

    // 复合赋值时，括号能提升可读性
    int r { 0 };
    r = (y *= z);                   // y becomes 15; r gets 15 (r 与 y 不同，无冲突)

    std::cout << std::boolalpha;
    std::cout << "x = " << x << '\n';
    std::cout << "cond = " << cond << '\n';
    std::cout << "r = " << r << ", y = " << y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
