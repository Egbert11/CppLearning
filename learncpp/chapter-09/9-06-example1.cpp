// 来源小节：9.6 Assert and static_assert
// 示例说明：用显式的零检查 + 错误信息处理"除数为零"这一坏参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example1.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDivision(int x, int y)
{
    if (y != 0)
        std::cout << static_cast<double>(x) / y;
    else
        std::cerr << "Error: Could not divide by zero\n";
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
