// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：把同样的代码改成 class——成员默认是 private，于是聚合初始化、
//           直接访问 m_day、调用 print() 三处都编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，保留原文标记为错误的
//       三处语句，请勿"修复"。
//       预期错误（g++）：no matching function for call to 'Date::Date(<brace-enclosed initializer list>)'
//                       'int Date::m_day' is private within this context
//                       'void Date::print() const' is private within this context
// ============================================================
#include <iostream>

class Date // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};     // private by default
    int m_month {};    // private by default
    int m_day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    today.m_day = 16; // compile error: the m_day member is private
    today.print();    // compile error: the print() member function is private

    return 0;
}
