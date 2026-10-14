// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：错误情形 1（无意义输入）的修正——用 while(true) + switch 验证输入，
//           只接受 +、-、*、/，否则提示并重新输入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example2.cpp -o a
// 这是交互式程序，需要用户输入。
// 输入非法字符（如 q）时预期输出：Oops, that input is invalid.  Please try again.
//
// 本节代码为按原文描述重建。

#include <iostream>

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

int main()
{
    std::cout << "You entered: " << getOperator() << '\n';

    return 0;
}
