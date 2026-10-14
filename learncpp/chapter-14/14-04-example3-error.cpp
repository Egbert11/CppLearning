// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：const 对象的数据成员在初始化之后不能再被修改：直接改成员、
//           或调用会修改成员的成员函数，都会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，保留原文中两处被
//       注释标记为错误的语句，请勿"修复"。
//       预期错误（g++）：assignment of member 'Date::day' in read-only object
//                       passing 'const Date' as 'this' argument discards qualifiers
// ============================================================
struct Date
{
    int year {};
    int month {};
    int day {};

    void incrementDay()
    {
        ++day;
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.day += 1;       // compile error: can't modify member of const object
    today.incrementDay(); // compile error: can't call member function that modifies member of const object

    return 0;
}
