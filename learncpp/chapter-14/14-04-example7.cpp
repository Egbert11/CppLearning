// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：const 成员函数既能用于 const 对象，也能用于非 const 对象——
//           此处 const 的 print() 被非 const 的 Date 对象调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // non-const

    today.print(); // ok: can call const member function on non-const object

    return 0;
}

// 预期输出：
// 2020/10/14
