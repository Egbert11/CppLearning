// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：以 0x 开头的字面量是十六进制。预期输出：15
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    int x { 0xF }; // 0x before the number means this is hexadecimal
    std::cout << x << '\n'; // prints 15

    return 0;
}
