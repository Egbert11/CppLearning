// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：成员函数可以像普通函数一样重载——print() 与 print(prefix)
//           依参数不同被区分，用同一个名字提供两种打印方式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print()
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    void print(std::string_view prefix)
    {
        std::cout << prefix << year << '/' << month << '/' << day << '\n';
    }
};

int main()
{
    Date today { 2020, 10, 14 };

    today.print();                // calls print()
    today.print("The date is: "); // calls print(std::string_view)

    return 0;
}

// 预期输出：
// 2020/10/14
// The date is: 2020/10/14
