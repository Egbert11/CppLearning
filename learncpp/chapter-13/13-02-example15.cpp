// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：更常用的做法是把枚举放进命名空间，得到一个独立的作用域区域，
//           用 `Color::blue`、`Feeling::tired` 这样带限定名来访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
namespace Color
{
    enum Color
    {
        red,
        green,
        blue,
    };
}

namespace Feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue,
    };
}

int main()
{
    [[maybe_unused]] Color::Color paint { Color::blue };
    [[maybe_unused]] Feeling::Feeling me { Feeling::tired };

    return 0;
}
