// ============================================================
// 来源小节：15.2 Classes and header files
// 文件说明：另一种写法——把类外的成员函数定义用 inline 关键字标出，
//           使其成为内联函数，从而可被多个翻译单元安全包含（不违反 ODR）。
//           此时头文件顶部要 #include <iostream>（因为 print() 用到了它）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
// 备注：本节代码为按原文描述重建。
// ============================================================
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day);

    void print() const;

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

// 用 inline 标记，避免多翻译单元包含时出现重复定义（ODR 违规）
inline Date::Date(int year, int month, int day)
    : m_year{ year }
    , m_month{ month }
    , m_day{ day }
{
}

inline void Date::print() const
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}

#endif
