// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：把 print() 声明为 const 成员函数（在参数列表之后、函数体之前
//           加 const）后，const 对象就可以调用它了。
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

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.print(); // ok: const object can call const member function

    return 0;
}

// 预期输出：
// 2020/10/14
