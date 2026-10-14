// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：聚合初始化（aggregate initialization）的两种主要形式——拷贝列表
//           初始化（= { ... }）和列表初始化（{ ... }）。推荐后者。值按成员
//           声明顺序逐一映射。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    // copy-list initialization using braced list
    [[maybe_unused]] Employee frank = { 1, 32, 60000.0 };

    // list initialization using braced list (preferred)
    [[maybe_unused]] Employee joe { 2, 28, 45000.0 };

    return 0;
}
