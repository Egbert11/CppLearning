// 来源小节：8.5 Switch statement basics
// 示例说明：用 break 代替 return——break 只退出 switch 块，之后函数继续执行（打印 " Ah-Ah-Ah!"）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example6.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   Three Ah-Ah-Ah!

#include <iostream>

void printDigitName(int x)
{
    switch (x)
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

    // execution continues here
    std::cout << " Ah-Ah-Ah!";
}

int main()
{
    printDigitName(3);
    std::cout << '\n';

    return 0;
}
