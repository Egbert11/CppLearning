// ============================================================
// 来源小节：5.2 Literals
// 示例说明：无后缀的 int 字面量可以用来初始化其他整型，编译器会自动转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int a { 5 };          // ok: types match
    unsigned int b { 6 }; // ok: compiler will convert int value 6 to unsigned int value 6
    long c { 7 };         // ok: compiler will convert int value 7 to long value 7
    // --- 原文示例片段结束 ---

    std::cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}
