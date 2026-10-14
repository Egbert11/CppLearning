// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：即使 print() 并不修改任何东西，只要它没有声明为 const，
//           const 对象就**不能**调用它——编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，请勿"修复"。
//       预期错误（g++）：passing 'const Date' as 'this' argument discards qualifiers
// ============================================================
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // non-const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.print(); // compile error: can't call non-const member function

    return 0;
}
