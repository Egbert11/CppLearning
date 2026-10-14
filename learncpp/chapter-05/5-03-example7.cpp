// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：用 std::dec / std::hex / std::oct 切换输出进制，
//           操纵符会持续生效直到被改变。预期输出：
//           12
//           c
//           c
//           14
//           12
//           12
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <iostream>

int main()
{
    int x { 12 };
    std::cout << x << '\n';             // decimal (by default)
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << x << '\n';             // now hexadecimal
    std::cout << std::oct << x << '\n'; // octal
    std::cout << std::dec << x << '\n'; // return to decimal
    std::cout << x << '\n';             // decimal

    return 0;
}
