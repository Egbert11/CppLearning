// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：以 const 引用传参是获得 const 对象的常见途径。doSomething() 里
//           形参是 const，因此调用非 const 的 print() 会编译失败——即便
//           调用处传入的是非 const 对象。
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

void doSomething(const Date& date)
{
    date.print(); // compile error: const object can't call non-const member function
}

int main()
{
    Date today { 2020, 10, 14 }; // non-const

    doSomething(today);

    return 0;
}
