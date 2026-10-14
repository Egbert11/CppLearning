// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：从一个 32 位 RGBA 像素值中，用掩码 + 右移提取各 8 位分量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 预期（输入 FF7F3300）：
//   ff red
//   7f green
//   33 blue
//   0 alpha
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] constexpr std::uint32_t redBits{   0xFF000000 };
    [[maybe_unused]] constexpr std::uint32_t greenBits{ 0x00FF0000 };
    [[maybe_unused]] constexpr std::uint32_t blueBits{  0x0000FF00 };
    [[maybe_unused]] constexpr std::uint32_t alphaBits{ 0x000000FF };

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate the pixels, then right shift into the range 0-255
    std::uint8_t red{   static_cast<std::uint8_t>((pixel & redBits)   >> 24) };
    std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    std::uint8_t blue{  static_cast<std::uint8_t>((pixel & blueBits)  >> 8) };
    std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

    std::cout << std::hex << static_cast<int>(red)   << " red\n";
    std::cout << std::hex << static_cast<int>(green) << " green\n";
    std::cout << std::hex << static_cast<int>(blue)  << " blue\n";
    std::cout << std::hex << static_cast<int>(alpha) << " alpha\n";
    // --- 原文示例片段结束 ---

    return 0;
}
