// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：尽管开头的 private: 是冗余的，不少开发者仍显式写出，以明确
//           表达"以下成员是私有的"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
class Foo
{
private: // redundant, but makes it clear that what follows is private
    int m_something {}; // private by default
};

int main()
{
    [[maybe_unused]] Foo f{};
    return 0;
}
