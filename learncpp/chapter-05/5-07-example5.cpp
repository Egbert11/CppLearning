// 来源小节：5.7 Introduction to std::string
// 示例说明：在 getline 前加上 std::ws 的修正版，能正确跳过遗留的换行与空白。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 11）。本程序需交互输入。
// 原文示例运行（先输入 2，再输入 Alex）：
//   Hello, Alex, you picked 2

#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // note: added std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
