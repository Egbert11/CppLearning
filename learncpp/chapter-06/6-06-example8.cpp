// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：四种括号模式——(1) 无复合表达式、条件简单；
//           (2) 简单表达式、条件含运算符；(3) 复合表达式、条件是函数调用；
//           (4) 复合表达式、条件含运算符。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建（为可编译补全上下文）。
// ============================================================
#include <iostream>
#include <string_view>

bool isAfternoon()
{
    return true;
}

// --- 原文示例片段 ---
// (1) no compound expression, simple condition -> no parentheses needed
int getMoves(bool isStunned, int movesLeft)
{
    return isStunned ? 0 : movesLeft; // no compound expression, simple condition
}

void printMax(int x, int y)
{
    // (2) simple expression, condition contains operators -> parenthesize the condition
    int z { (x > y) ? x : y };
    std::cout << "z = " << z << '\n';

    // (3) compound expression, condition is a function call -> parenthesize the whole conditional
    std::cout << (isAfternoon() ? "PM" : "AM") << '\n';

    // (4) compound expression, condition contains operators -> parenthesize both
    std::cout << ((x > y) ? x : y) << '\n';
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << getMoves(false, 5) << '\n';
    printMax(3, 4);
    return 0;
}
