// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：C++17 起，有作用域枚举也可以直接用整数做列表初始化，且无需显式
//           指定底层类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建（沿用上一例的 Pet 定义）。
// ============================================================
enum class Pet
{
    cat,
    dog,
    pig,
    whale,
};

int main()
{
    Pet pet { 1 }; // okay, list-initialize a scoped enum with an integer (C++17)

    (void)pet;
    return 0;
}
