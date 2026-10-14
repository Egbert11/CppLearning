// ============================================================
// 来源小节：15.2 Classes and header files
// 示例说明：把声明与实现分离——构造函数与 print() 在类里只写原型，
//           定义放到类外面，定义时成员函数名前要加上类名限定
//           （Date::）。访问函数很简单，仍留在类内。
// 原文链接：https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
// 预期输出：Date(2015, 10, 14)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day); // 构造函数原型

    void print() const; // print 函数原型

    // 访问函数（trivial）仍定义在类内，以免多出一堆额外代码
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

// 类外定义：成员函数名前加类名限定 Date::
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

int main()
{
    const Date d{ 2015, 10, 14 };
    d.print();

    return 0;
}
