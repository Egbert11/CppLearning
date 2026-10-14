// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：用 public: / private: 访问说明符显式划分成员的可访问性；
//           说明符影响其后所有成员，直到下一个说明符出现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。原文的成员初值为 year 2020、
//       month 14、day 10（原文如此），故输出为 2020/14/10。
// ============================================================
#include <iostream>

class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

private: // here's our private access specifier

    int m_year { 2020 }; // private due to above private: specifier
    int m_month { 14 };  // private due to above private: specifier
    int m_day { 10 };    // private due to above private: specifier
};

int main()
{
    Date d{};
    d.print(); // okay, main() allowed to access public members

    return 0;
}

// 预期输出：
// 2020/14/10
