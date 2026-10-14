// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：无作用域枚举的枚举量会进入枚举所在的作用域（这里是全局作用域），
//           因此 `red` 既可以直接写，也可以写成 `Color::red`——枚举本身
//           也算一个"具名作用域区域"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum Color
{
    red,
    green,
    blue,
};

int main()
{
    // 因为 red/green/blue 在全局作用域，下面几种写法都合法：
    [[maybe_unused]] Color apple { red };
    [[maybe_unused]] Color sky { Color::blue };   // 使用作用域解析运算符也可以
    [[maybe_unused]] Color night { Color::green };

    return 0;
}
