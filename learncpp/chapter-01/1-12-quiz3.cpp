// 来源小节：1.x Chapter 1 summary and quiz（官方编号 1.x）
// 题目：第 3 题——编写程序，要求用户输入两个整数，然后打印它们的和与差。
//       提示：要输出“句点 + 换行”，应使用 ".\n" 而不是 '.\n'（后者是多字符字面量）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/
//
// 预期运行（假设输入 6 和 4）：
//   Enter an integer: 6
//   Enter another integer: 4
//   6 + 4 is 10.
//   6 - 4 is 2.
//
// 编译：g++ -std=c++20 -Wall 1-12-quiz3.cpp -o quiz3

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";

    return 0;
}
