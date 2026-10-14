// 来源小节：8.5 Switch statement basics
// 示例说明：标签缩进的推荐格式——标签与 switch 块的内层对齐，标签下的语句再缩进一层。
//           这让每个标签都容易看到，并且（正确地）暗示所有语句共享 switch 块的作用域。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example9.cpp -o a
//
// 本节代码为按原文描述重建（原文示例 7/8 为"不可读/可接受但不推荐"的排版，示例 9 为推荐排版；
// 这里只生成推荐版本，另两种排版在 md 的"核心概念"中说明）。

#include <iostream>

void printDigitName(int x)
{
    switch (x) // preferred version
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    default:
        std::cout << "Unknown";
        break;
    }
}

int main()
{
    for (int i{ 1 }; i <= 4; ++i)
    {
        printDigitName(i);
        std::cout << '\n';
    }

    return 0;
}
