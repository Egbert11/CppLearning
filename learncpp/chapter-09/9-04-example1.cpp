// 来源小节：9.4 Detecting and handling errors
// 示例说明：静默失败——当 y 为 0 时函数什么都不做，也不向调用者报告任何信息。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example1.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDivision(int x, int y)
{
    if (y != 0) // silent failure if y=0
        std::cout << static_cast<double>(x) / y << '\n';
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    printDivision(x, y);

    return 0;
}
