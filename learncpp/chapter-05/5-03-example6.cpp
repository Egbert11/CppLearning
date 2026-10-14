// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：数字分隔符 ' 用于视觉分组，不改变数值；不能放在第一个数字前。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int bin { 0b1011'0010 };      // 分组显示为 1011 0010，值仍是 178
    long value { 2'132'673'462 }; // much easier to read than 2132673462

    // int bin { 0b'1011'0010 };  // error: ' used before first digit of value
    // --- 原文示例片段结束 ---

    std::cout << bin << '\n' << value << '\n';

    return 0;
}
