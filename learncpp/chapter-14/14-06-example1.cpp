// ============================================================
// 来源小节：14.6 Access functions
// 示例说明：class 的数据成员默认为 private——对象能打印自己，但外部代码
//           无法读取或修改它的 m_year 等成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/access-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Date
{
private:
    int m_year{ 2020 };
    int m_month{ 10 };
    int m_day{ 14 };

public:
    void print() const
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

int main()
{
    Date d{};  // create a Date object
    d.print(); // print the date

    return 0;
}

// 预期输出：
// 2020/10/14
