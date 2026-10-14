// ============================================================
// 来源小节：13.5 Introduction to overloading the I/O operators
// 示例说明：用辅助函数 getColorName 把枚举转成字符串来打印。两个缺点：
//           要记住函数名；而且调用它会让输出语句变得累赘。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/
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
