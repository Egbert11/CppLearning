// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：C++20 的 using enum 语句把某个枚举的所有枚举量引入当前作用域，
//           从而在 switch 里可以写 case black: 而不必写 case Color::black:。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

enum class Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColor(Color color)
{
    using enum Color; // bring all Color enumerators into the current scope (C++20)

    switch (color)
    {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main()
{
    Color shirt { Color::blue };

    std::cout << "Your shirt is " << getColor(shirt) << '\n';

    return 0;
}

// 预期输出：
// Your shirt is blue
