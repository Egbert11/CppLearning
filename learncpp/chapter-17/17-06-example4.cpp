// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：用名字数组替换 switch/if 链——数组可用枚举值作下标取名字，也可
//           反向遍历用名字查回枚举；配合为枚举类型重载的 operator<< 与
//           operator>> 实现完整的输入输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出：Your shirt is blue
//            Enter a new color: red
//            Your shirt is now red
//           （第二行后的 "red" 为输入）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>
#include <string>
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

    // use a std::string_view for the name
    using namespace std::string_view_literals;
    constexpr std::array colorName { "black"sv, "red"sv, "blue"sv };
    static_assert(std::size(colorName) == max_colors);

    constexpr std::string_view getColorName(Type color)
    {
        return colorName[static_cast<std::size_t>(color)];
    }

    std::ostream& operator<<(std::ostream& out, Type color)
    {
        out << getColorName(color);
        return out;
    }

    std::istream& operator>>(std::istream& in, Type& color)
    {
        std::string name{};
        in >> name;

        for (std::size_t i{ 0 }; i < colorName.size(); ++i)
        {
            if (colorName[i] == name)
            {
                color = static_cast<Type>(i);
                return in;
            }
        }

        // no match: fail the stream
        in.setstate(std::ios_base::failbit);

        // On a failed extraction, operator>> zero-initializes fundamental types;
        // uncomment the next line to mimic that behavior for our enum.
        // color = static_cast<Type>(0);

        return in;
    }
}

int main()
{
    Color::Type shirt { Color::blue };
    std::cout << "Your shirt is " << shirt << '\n';

    std::cout << "Enter a new color: ";
    std::cin >> shirt;

    std::cout << "Your shirt is now " << shirt << '\n';

    return 0;
}
