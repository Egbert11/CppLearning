// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：逐条区分常量表达式与运行期表达式。
// 原文中的独立表达式语句会带来“statement has no effect”告警，
// 这是原文的展示方式，编译不受影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int five()
{
    return 5;
}

int main()
{
    // --- 原文示例片段 ---
    // Literals
    5;               // constant expression
    1.2;             // constant expression
    "Hello world!";  // constant expression (C-style string literal)

    // Operators with constant expression operands
    5 + 6;           // constant expression
    1.2 * 3.4;       // constant expression
    8 - 5.6;         // constant expression
    sizeof(int) + 1; // constant expression

    // Function calls
    getNumber();     // runtime expression
    five();          // runtime expression (five() is not constexpr)

    // Output
    std::cout << 5;  // runtime expression (output happens at runtime)
    // --- 原文示例片段结束 ---

    return 0;
}
