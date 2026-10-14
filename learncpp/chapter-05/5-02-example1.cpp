// ============================================================
// 来源小节：5.2 Literals
// 示例说明：把各种类型的字面量直接写进代码，并用注释标注其类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x = 5;                    // 5 is an integer literal
    bool myNameIsAlex { true };   // true is a boolean literal
    double d { 3.4 };             // 3.4 is a double literal
    std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    std::cout << x << ' ' << myNameIsAlex << ' ' << d << '\n';

    return 0;
}
