// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：把一切合起来的健壮计算器——ignoreLine()、clearFailedExtraction()
//           （遇 EOF 时 std::exit(0)）、经验证的 getDouble()/getOperator()、
//           处理除零与意外运算符的 printResult()，以及除零时重新提示的 main() 循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example7.cpp -o a
// 这是交互式程序，需要用户输入。
//
// 本节代码为按原文描述重建（原文示例 12）。

#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if a failed extraction was cleared, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        ignoreLine(); // remove any extraneous input
        return x;     // return the value we extracted
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        if (!clearFailedExtraction()) // we'll handle error messaging if extraction failed below
            ignoreLine();             // remove any extraneous input (only if extraction succeeded)

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;
        default:
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }
}

void printResult(double x, char operation, double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
    case '+':
        std::cout << x + y << '\n';
        return;
    case '-':
        std::cout << x - y << '\n';
        return;
    case '*':
        std::cout << x * y << '\n';
        return;
    case '/':
        if (y == 0.0)
            break; // cannot divide by zero, so fall through to the "???" case below

        std::cout << x / y << '\n';
        return;
    }

    std::cout << "???"; // Being here means an unknown operator is being used
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    while (operation == '/' && y == 0.0)
    {
        std::cout << "The denominator cannot be zero.  Try again.\n";
        y = getDouble();
    }

    printResult(x, operation, y);

    return 0;
}
