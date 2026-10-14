// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：C++14 起可用 0b 前缀直接书写二进制字面量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int bin {};        // assume 16-bit int
    bin = 0b1;         // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;        // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;      // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000;  // assign binary 0000 0000 1111 0000 to the variable
    // --- 原文示例片段结束 ---

    std::cout << bin << '\n'; // prints 240

    return 0;
}
