// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：一个被声明为 const 的成员函数若在函数体里修改了数据成员，
//           就违背了自己的承诺，编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，请勿"修复"。
//       预期错误（g++）：increment of member 'Date::day' in read-only object
// ============================================================
struct Date
{
    int year {};
    int month {};
    int day {};

    void incrementDay() const // made const
    {
        ++day; // compile error: const function can't modify member
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.incrementDay();

    return 0;
}
