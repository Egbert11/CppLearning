// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：对"值从 0 起、每次加 1"的枚举，可用整型计数器遍历，但每次都要
//           static_cast 回枚举类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出：black
//            red
//            blue
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>
#include <string_view>

namespace Color
{
    enum Type
    {
        black,
        red,
        blue,
        max_colors
    };

    using namespace std::string_view_literals;
    constexpr std::array colorName { "black"sv, "red"sv, "blue"sv };
    static_assert(std::size(colorName) == max_colors);

    constexpr std::string_view getColorName(Type color)
    {
        return colorName[static_cast<std::size_t>(color)];
    }
}

int main()
{
    for (int i{ 0 }; i < Color::max_colors; ++i)
        std::cout << Color::getColorName(static_cast<Color::Type>(i)) << '\n';

    return 0;
}
