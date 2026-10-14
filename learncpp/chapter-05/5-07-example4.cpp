// 来源小节：5.7 Introduction to std::string
// 示例说明：遗留换行 bug——先用 std::cin >> 读入数字，换行符留在流中，
//           随后的 std::getline()（未加 std::ws）会立刻读到空字符串。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 10）。本程序需交互输入。
// 原文示例运行（先输入 2，再输入 Alex）会得到：
//   Hello, , you picked 2

#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // note: no std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
