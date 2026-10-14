// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：给进阶读者——编译器实际把"在类内定义的成员函数"视为在类内
//           前置声明、然后把函数体挪到类定义之后。此处用等价的类外定义写法
//           展示这一点：编译函数体时整个类已知，所以成员顺序无关紧要。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
struct Foo
{
    int z();            // forward declared
    int x();            // forward declared
    int m_data{};       // hmm, this is the member
    int y();            // forward declared
};

// Definitions moved after the class definition
int Foo::z() { return m_data; }
int Foo::x() { return y(); }
int Foo::y() { return 5; }

int main()
{
    [[maybe_unused]] Foo f{};
    return 0;
}
