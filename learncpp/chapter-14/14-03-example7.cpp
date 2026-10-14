// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：与非成员不同，类内部的成员可以"先用后声明"——数据成员与
//           成员函数以任意顺序出现都能互相引用，包括默认成员初始化器里。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。成员的初始化顺序仍是按声明顺序，
//       详见 14-03-example8-ub.cpp。
// ============================================================
struct Foo
{
    int z() { return m_data; }
    int x() { return y(); }
    int m_data { y() }; // 默认成员初始化器里调用稍后才声明的 y()
    int y() { return 5; }
};

int main()
{
    [[maybe_unused]] Foo f{};
    return 0;
}
