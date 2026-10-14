// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：一个没有任何错误处理的简易计算器（原文的第一个示例）。
//           正常运行时例如输入 5、*、7，输出 "5 * 7 is 35"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example1.cpp -o a
// 这是交互式程序，需要用户输入。
//
// 本节代码为按原文描述重建。

#include <iostream>

double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char operation{};
    std::cin >> operation;
    return operation;
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}
