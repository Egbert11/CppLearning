// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：把上一例改成有作用域枚举（enum class）后，跨枚举比较不再是
//           "隐式转 int 后相等"，而会直接编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。预期编译失败（color == fruit）。
// ============================================================
#include <iostream>

enum class Color
{
    red,
    blue,
};

enum class Fruit
{
    banana,
    apple,
};

int main()
{
    Color color { Color::red };
    Fruit fruit { Fruit::banana };

    if (color == fruit) // compile error: enum class doesn't implicitly convert to int
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

    return 0;
}
