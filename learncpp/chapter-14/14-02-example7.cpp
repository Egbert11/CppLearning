// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：把 14-02-example1.cpp 改写为 class：加上 public: 访问说明符，
//           并给每个成员加 m_ 前缀。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Date       // we changed struct to class
{
public:          // and added this line, which is called an access specifier
    int m_day{}; // and added "m_" prefixes to each of the member names
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    printDate(date);

    return 0;
}

// 预期输出：
// 4/10/21
