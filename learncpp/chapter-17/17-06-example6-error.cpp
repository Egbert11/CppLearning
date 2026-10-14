// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：不能对枚举类型使用基于范围的 for 循环——枚举不是可遍历的范围。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期错误：编译错误——'Color::Type' is not a class, namespace, or enumeration
//           （枚举类型不能作为范围）。
// 备注：本文件为预期编译失败示例（-error），请勿修复。正确做法见
//       17-06-example7.cpp：把枚举项放进数组再遍历。
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
}

int main()
{
    for (auto c: Color::Type) // compile error: can't traverse enumeration
        std::cout << c << '\n';

    return 0;
}
