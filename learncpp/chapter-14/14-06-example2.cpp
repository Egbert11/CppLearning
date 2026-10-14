// ============================================================
// 来源小节：14.6 Access functions
// 示例说明：为 Date 提供一整套 getter / setter 访问函数（存取函数）。
//           getter 通常标 const，能在 const 与非 const 对象上调用；
//           setter 非 const，用于修改数据成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/access-functions/
// 备注：本节代码为按原文描述忠实重建。原文此例的 print() 未标 const。
// ============================================================
#include <iostream>

class Date
{
private:
    int m_year { 2020 };
    int m_month { 10 };
    int m_day { 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int getYear() const { return m_year; }        // getter for year
    void setYear(int year) { m_year = year; }     // setter for year

    int getMonth() const  { return m_month; }     // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() const { return m_day; }          // getter for day
    void setDay(int day) { m_day = day; }         // setter for day
};

int main()
{
    Date d{};
    d.setYear(2021);
    std::cout << "The year is: " << d.getYear() << '\n';

    return 0;
}

// 预期输出：
// The year is: 2021
