// ============================================================
// 来源小节：6.2 Arithmetic operators
// 示例说明：整数除法除以用户输入值。两个操作数均为 int，故为整数除法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-operators/
// !! -ub：整数除以 0 是未定义行为，程序很可能崩溃。输入 0 即可触发。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int apples { 12 };
    std::cout << "How many people do you want to divide " << apples << " apples between? ";
    int x {};
    std::cin >> x;

    // Both x and apples are int, so this is integer division
    // x == 0 will cause undefined behavior (crash likely)
    std::cout << "Each person gets " << apples / x << " whole apples.\n";
    // --- 原文示例片段结束 ---

    return 0;
}
