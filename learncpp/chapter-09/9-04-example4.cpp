// 来源小节：9.4 Detecting and handling errors
// 示例说明：把错误传回给调用者——把 void 函数改成返回 bool，用返回值表示成功/失败，
//           让调用者可以检查。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example4.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

bool printIntDivision(int x, int y)
{
    if (y == 0)
    {
        std::cout << "Error: could not divide by zero\n";
        return false;
    }

    std::cout << x / y << '\n';
    return true;
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    if (!printIntDivision(x, y))
        std::cout << "That was an error\n";

    return 0;
}
