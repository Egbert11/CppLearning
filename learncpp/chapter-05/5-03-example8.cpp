// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：std::cout 没有内建二进制输出，用 std::bitset 打印。
//           预期输出：
//           11000101
//           11000101
//           1010
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <bitset>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::bitset<8> bin1 { 0b1100'0101 }; // binary literal for binary 1100 0101
    std::bitset<8> bin2 { 0xC5 };        // hexadecimal literal for binary 1100 0101

    std::cout << bin1 << '\n' << bin2 << '\n';
    std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset<4> and print it
    // --- 原文示例片段结束 ---

    return 0;
}
