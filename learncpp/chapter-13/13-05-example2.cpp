// ============================================================
// 来源小节：13.5 Introduction to overloading the I/O operators
// 示例说明：为 operator<< 写一个重载，教 std::ostream 如何打印一个 Color。
//           左侧参数是非 const 的 std::ostream&（避免拷贝，且流本身要被修改），
//           返回类型与左操作数一致（std::ostream&），以便链式调用。
//           参数名用 out 而不是 std::cout，这样调用者可以选择输出流
//           （例如 std::cerr << color 也能工作）。
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

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
    out << getColorName(color); // print our color's name to whatever output stream out
    return out;                 // operator<< conventionally returns its left operand

    // The above can be condensed to the following single line:
    // return out << getColorName(color);
}

int main()
{
    Color shirt{ blue };

    std::cout << "Your shirt is " << shirt << '\n'; // it works!

    return 0;
}

// 预期输出：
// Your shirt is blue
