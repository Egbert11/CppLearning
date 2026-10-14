// 来源小节：8.5 Switch statement basics
// 示例说明：把示例 1 改写为 switch 语句，每个 case 用 return 结束，并带 default。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example2.cpp -o a
//
// 本节代码为按原文描述重建（含原文示例 3 的注释标注）。
//
// 原文预期输出：
//   Two

#include <iostream>

void printDigitName(int x)
{
    switch (x) // x is evaluated to produce value 2
    {
    case 1:
        std::cout << "One";
        return;
    case 2:
        std::cout << "Two"; // execution begins here
        return;
    case 3:
        std::cout << "Three";
        return;
    default:
        std::cout << "Unknown";
        return;
    }
}

int main()
{
    printDigitName(2);
    std::cout << '\n';

    return 0;
}
