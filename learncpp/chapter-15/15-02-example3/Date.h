// ============================================================
// 来源小节：15.2 Classes and header files
// 文件说明：多文件示例——Date 类放在头文件 Date.h 中（含头文件保护），
//           以便被多个 .cpp 包含复用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
// 备注：本节代码为按原文描述重建。
// ============================================================
#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day);

    void print() const;

    // 访问函数很简单，仍在类内定义
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

#endif
