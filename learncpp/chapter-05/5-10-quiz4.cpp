// 来源小节：5.x Chapter 5 summary and quiz（测验第 4 题）
// 题目：编写程序，要求用户输入两个人的姓名与年龄，然后打印出较年长者的姓名与年龄。
//       要求：用 std::string 存储字符串，用 std::string_view 作为只读函数形参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（测验第 4 题解答）。本程序需交互输入。
// 原文提示：用 std::getline() 输入姓名。
// 参考示例输出（名字 David Jenkins/44，John Bacon/37）：
//   Enter the name of person #1: David Jenkins
//   Enter the age of David Jenkins: 44
//   Enter the name of person #2: John Bacon
//   Enter the age of John Bacon: 37
//   David Jenkins (age 44) is older than John Bacon (age 37).

#include <iostream>
#include <string>
#include <string_view>

std::string getName(int num)
{
    std::cout << "Enter the name of person #" << num << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
    return name;
}

int getAge(std::string_view sv)
{
    std::cout << "Enter the age of " << sv << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 << ") is older than "
                  << name2 << " (age " << age2 << ").\n";
    else
        std::cout << name2 << " (age " << age2 << ") is older than "
                  << name1 << " (age " << age1 << ").\n";
}

int main()
{
    const std::string name1{ getName(1) };
    const int age1{ getAge(name1) };

    const std::string name2{ getName(2) };
    const int age2{ getAge(name2) };

    printOlder(name1, age1, name2, age2);

    return 0;
}
