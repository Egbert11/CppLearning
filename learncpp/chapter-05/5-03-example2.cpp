// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：以 0 开头的字面量是八进制。八进制 12 == 十进制 10，
//           因此预期输出：10
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    int x { 012 }; // 0 before the number means this is octal
    std::cout << x << '\n'; // prints 10 (octal 12 == decimal 10)

    return 0;
}
