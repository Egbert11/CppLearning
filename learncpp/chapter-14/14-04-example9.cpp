// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：把上一例的 print() 改成 const 成员函数后，const 引用形参
//           就能成功调用它了。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const // now a const member function
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

void doSomething(const Date& date)
{
    date.print(); // ok: const object can call const member function
}

int main()
{
    Date today { 2020, 10, 14 }; // non-const

    doSomething(today);

    return 0;
}

// 预期输出：
// 2020/10/14
