// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：有作用域枚举的枚举量只在其自身作用域内可见——不能直接写 red，
//           必须写 Color::red；而且它不会隐式转成 int，所以直接打印也会失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。预期编译失败（未限定名 + 打印）。
//       原文指出 `Color color { Color::blue };` 这种写法是合法的。
// ============================================================
#include <iostream>

enum class Color
{
    red,
    blue,
};

int main()
{
    Color color { red }; // compile error: red is not in scope, must be Color::red
    color = blue;        // compile error: blue is not in scope, must be Color::blue

    std::cout << color;  // compile error: no operator<< for Color, no implicit int conversion

    return 0;
}
