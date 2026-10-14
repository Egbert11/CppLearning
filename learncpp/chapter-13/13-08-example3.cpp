// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：C++20 起可以用带括号的值列表初始化某些聚合体（直接初始化），但
//           遇到花括号省略（尤其是 std::array）会失败，因此不推荐。
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
    // direct initialization using parenthesized list (C++20)
    [[maybe_unused]] Employee robert ( 3, 45, 62500.0 );

    return 0;
}
