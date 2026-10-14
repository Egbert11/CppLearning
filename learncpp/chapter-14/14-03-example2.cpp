// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：成员函数版本——把 print() 移进 Date 内部，它即可隐式作用于
//           调用它的那个对象（隐式对象），成员名字无需前缀即可访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。原文此时尚未引入 const 成员函数，
//       故 print() 是非 const 的。
// ============================================================
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variable
    today.print();  // member function call

    return 0;
}

// 预期输出：
// 2020/10/16
