// 来源小节：5.7 Introduction to std::string
// 示例说明：用 std::getline(std::cin >> std::ws, ...) 读取整行，
//           修正“全名读到第一个空白即停”的问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 9）。本程序需交互输入。
// 原文示例运行（输入 John Doe / blue）：
//   Your name is John Doe and your favorite color is blue

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}
