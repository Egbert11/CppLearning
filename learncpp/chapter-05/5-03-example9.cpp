// ============================================================
// 来源小节：5.3 Numeral systems (decimal, binary, hexadecimal, and octal)
// 示例说明：C++20 的 Format 库与 C++23 的 Print 库输出二进制。
//           需要 C++23 的 <print>，并用 GCC 14+ 编译。
//           注意：本机 GCC 15 链接 <print> 时需要额外链接 libstdc++exp：
//           g++ -std=c++23 -Wall 5-03-example9.cpp -lstdc++exp
//           预期输出：
//           1010
//           0b1010
//           1010 0b1010
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
// ============================================================
#include <format>
#include <iostream>
#include <print> // C++23

int main()
{
    // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:b}\n", 0b1010);
    // C++20, {:#b} formats the argument as 0b-prefixed binary digits
    std::cout << std::format("{:#b}\n", 0b1010);

    // C++23, {:b} formats the argument as binary digits
    std::println("{:b} {:#b}", 0b1010, 0b1010);

    return 0;
}
