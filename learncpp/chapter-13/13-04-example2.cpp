// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：写一个函数，用 switch 把枚举量映射成名字字符串。返回 std::string_view
//           是安全的，因为它指向的 C 风格字符串字面量在程序整个生命周期都存在；
//           加 constexpr 还能让它在常量表达式中使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

enum Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColorName(Color color)
{
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
    constexpr Color shirt{ blue };

    std::cout << "Your shirt is " << getColorName(shirt) << '\n';

    return 0;
}

// 预期输出：
// Your shirt is blue
