// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：struct 把多个成员变量打包成一个对象，可以整体初始化、
//           整体传给函数（printDate 接收 const Date&）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Date
{
    int day{};
    int month{};
    int year{};
};

void printDate(const Date& date)
{
    std::cout << date.day << '/' << date.month << '/' << date.year; // assume DMY format
}

int main()
{
    Date date{ 4, 10, 21 }; // initialize using aggregate initialization
    printDate(date);        // can pass entire struct to function

    return 0;
}

// 预期输出：
// 4/10/21
