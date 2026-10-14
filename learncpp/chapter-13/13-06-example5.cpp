// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：有作用域枚举不会隐式转成整数，所以要输出其数值必须显式
//           static_cast<int>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。C++23 可用 std::to_underlying，
//       见 13-06-example5-cpp23.cpp。
// ============================================================
#include <iostream>

enum class Color
{
    black,
    red,
    blue,
};

int main()
{
    Color color { Color::red };

    // std::cout << color; // compile error: no implicit conversion to int
    std::cout << static_cast<int>(color) << '\n'; // prints 1

    return 0;
}

// 预期输出：
// 1
