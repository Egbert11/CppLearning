// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：C++20 的指定初始化器（designated initializer）——可以点明每个值
//           对应哪个成员；未被指定的成员会被值初始化。两种写法（花括号和 =）
//           都合法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。顺序错误的情况见 13-08-example10-error.cpp。
// ============================================================
struct Foo
{
    int a {};
    int b {};
    int c {};
};

int main()
{
    [[maybe_unused]] Foo f1{ .a{ 1 }, .c{ 3 } }; // f1.b value-initialized
    [[maybe_unused]] Foo f2{ .a = 1, .c = 3 };

    return 0;
}
