// 来源小节：5.7 Introduction to std::string
// 示例说明：std::cin >> 遇空白即停的 bug——读“全名”只会读到第一个单词，
//           随后的“颜色”输入被跳过的空格/名字剩余部分影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 8）。本程序需交互输入。
// 原文示例运行（输入 John Doe / blue）会产生类似：
//   Your name is John and your favorite color is Doe

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::cin >> color;

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}
