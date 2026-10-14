// ============================================================
// 来源小节：15.2 Classes and header files
// 文件说明：Date.cpp 提供 Date 类中非平凡成员函数的类外定义。
//           它必须与 Date.h 一起被编译进使用该类的项目，链接器才能解析调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
// 备注：本节代码为按原文描述重建。
// ============================================================
#include "Date.h"
#include <iostream>

Date::Date(int year, int month, int day)
    : m_year{ year }
    , m_month{ month }
    , m_day{ day }
{
}

void Date::print() const
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}
