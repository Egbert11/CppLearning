// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：两个无作用域枚举在同一作用域内不能重用同名枚举量。Color 与
//           Feeling 都想定义 blue，导致重定义错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。预期编译失败：枚举量 blue 重定义。
// ============================================================
enum Color
{
    red,
    green,
    blue,
};

enum Feeling
{
    happy,
    tired,
    blue, // error: blue is already defined in this scope
};

int main()
{
    return 0;
}
