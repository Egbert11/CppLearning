// 来源小节：9.4 Detecting and handling errors
// 示例说明：在函数内部处理错误——当 y 为 0 时取消操作，并打印错误信息告知用户原因。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example2.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
// 若第二个数为 0，预期输出：Error: Could not divide by zero
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDivision(int x, int y)
{
    if (y != 0)
        std::cout << static_cast<double>(x) / y << '\n';
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
