// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：class 默认就是 private，因此开头的 private: 说明符可以省略。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
class Foo
{
// private access specifier not required here since classes default to private members
    int m_something {}; // private by default
};

int main()
{
    [[maybe_unused]] Foo f{};
    return 0;
}
