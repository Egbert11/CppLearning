// ============================================================
// 来源小节：15.2 Classes and header files
// 示例说明：最简单的 Date 类——全部成员函数都定义在类定义内部。
//           类很小时这样做没问题，但类一大就会让实现细节"淹没"公共接口。
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
    Date(int year, int month, int day)
        : m_year{ year }
        , m_month{ month }
        , m_day{ day }
    {
    }

    void print() const
    {
        std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
    };

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

int main()
{
    Date d{ 2015, 10, 14 };
    d.print();

    return 0;
}
