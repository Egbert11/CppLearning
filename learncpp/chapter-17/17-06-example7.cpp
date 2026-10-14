// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：推荐做法——因为基于范围的 for 能作用于数组，就把每个枚举项放进
//           一个 constexpr std::array，再遍历该数组；循环变量由元素类型
//           推导为枚举类型本身。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出：black
//            red
//            blue
// 备注：本节代码为按原文描述重建。该技巧仅在枚举项取值互不相同时成立。
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

    // An array of enumerators so we can use a range-based for loop
    constexpr std::array types { black, red, blue }; // deduce std::array<Type, 3>
    static_assert(std::size(types) == max_colors);
}

int main()
{
    for (auto c : Color::types) // ok: we can iterate over the array elements
        std::cout << Color::getColorName(c) << '\n';

    return 0;
}
