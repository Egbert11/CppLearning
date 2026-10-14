// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：指定初始化器必须按成员声明顺序书写，否则报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。预期编译失败：
//       "designator order for field 'Foo::a' does not match declaration order"。
// ============================================================
struct Foo
{
    int a {};
    int b {};
    int c {};
};

int main()
{
    Foo f3{ .b{ 2 }, .a{ 1 } }; // error: designators must be in declaration order

    return 0;
}
