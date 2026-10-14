// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：struct 类型的变量可以是 const/constexpr，和以往一样必须初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
struct Rectangle
{
    double length {};
    double width {};
};

int main()
{
    const Rectangle unit { 1.0, 1.0 };
    const Rectangle zero { }; // value-initialize all members

    (void)unit;
    (void)zero;
    return 0;
}
