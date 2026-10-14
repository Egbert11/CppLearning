// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：没有前缀的数字默认按十进制解释。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    int x { 12 }; // 12 is assumed to be a decimal number
    std::cout << x << '\n';

    return 0;
}
