// 来源小节：8.5 Switch statement basics
// 示例说明：if-else 链版本——把数字映射为英文单词，用来与后面的 switch 版本对比。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   Two

#include <iostream>

void printDigitName(int x)
{
    if (x == 1)
        std::cout << "One";
    else if (x == 2)
        std::cout << "Two";
    else if (x == 3)
        std::cout << "Three";
    else
        std::cout << "Unknown";
}

int main()
{
    printDigitName(2);
    std::cout << '\n';

    return 0;
}
