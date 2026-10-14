// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：非成员函数版本——Date 的属性（成员变量）与行为（自由函数
//           print()）分开定义，读者只能从 const Date& 形参推断两者关系。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};
};

void print(const Date& date)
{
    std::cout << date.year << '/' << date.month << '/' << date.day;
}

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables are accessible by default
    print(today);

    return 0;
}

// 预期输出：
// 2020/10/16
