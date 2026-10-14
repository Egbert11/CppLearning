// 来源小节：8.5 Switch statement basics
// 示例说明：没有 case 匹配但存在 default —— 执行 default 的语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example4.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（x = 5）：
//   Unknown

#include <iostream>

void printDigitName(int x)
{
    switch (x) // x evaluates to 5
    {
    case 1:
        std::cout << "One";
        return;
    case 2:
        std::cout << "Two";
        return;
    case 3:
        std::cout << "Three";
        return;
    default: // no case matched, so default is taken
        std::cout << "Unknown";
        return;
    }
}

int main()
{
    printDigitName(5);
    std::cout << '\n';

    return 0;
}
