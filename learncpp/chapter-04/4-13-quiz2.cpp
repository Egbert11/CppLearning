// 来源小节：4.x Chapter 4 summary and quiz
// 题目：Question 2 —— 读入两个 double 和一个运算符（+、-、*、/），计算并打印结果；
//       若运算符无效则不打印任何内容。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
// 示例运行：
//   Enter a double value: 6.2
//   Enter a double value: 5
//   Enter +, -, *, or /: *
//   6.2 * 5 is 31

#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double x, char operation, double y)
{
    if (operation == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (operation == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (operation == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (operation == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
    else
        return; // if the user did not pass in a supported operation
}

int main()
{
    double x{ getDouble() };
    double y{ getDouble() };

    char operation{ getOperator() };

    printResult(x, operation, y);

    return 0;
}
