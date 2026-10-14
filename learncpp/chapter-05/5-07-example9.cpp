// 来源小节：5.7 Introduction to std::string（测验解答）
// 示例说明：读取用户全名（getline + std::ws）与年龄，把无符号的字符串长度
//           转换成有符号 int 后与年龄相加输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 16 / 测验解答）。本程序需交互输入。
// 原文示例运行（名字 "John Doe"，年龄 32）：
//   Enter your full name: John Doe
//   Enter your age: 32
//   Your age + length of name is: 40

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    int age{}; // age needs to be an integer, not a string
    std::cin >> age;

    int nameLen { static_cast<int>(name.length()) }; // get number of chars in name (including spaces)
    std::cout << "Your age + length of name is: " << age + nameLen << '\n';

    return 0;
}
