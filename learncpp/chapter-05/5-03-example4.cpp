// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：C++14 之前没有二进制字面量，常以十六进制表示二进制位模式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int bin {};    // assume 16-bit int
    bin = 0x0001;  // assign binary 0000 0000 0000 0001 to the variable
    bin = 0x0002;  // assign binary 0000 0000 0000 0010 to the variable
    bin = 0x0004;  // assign binary 0000 0000 0000 0100 to the variable
    bin = 0x0008;  // assign binary 0000 0000 0000 1000 to the variable
    bin = 0x0010;  // assign binary 0000 0000 0001 0000 to the variable
    bin = 0x0020;  // assign binary 0000 0000 0010 0000 to the variable
    bin = 0x0040;  // assign binary 0000 0000 0100 0000 to the variable
    bin = 0x0080;  // assign binary 0000 0000 1000 0000 to the variable
    bin = 0x00FF;  // assign binary 0000 0000 1111 1111 to the variable
    bin = 0x00B3;  // assign binary 0000 0000 1011 0011 to the variable
    bin = 0xF770;  // assign binary 1111 0111 0111 0000 to the variable
    // --- 原文示例片段结束 ---

    std::cout << bin << '\n'; // prints 63344 (0xF770)

    return 0;
}
