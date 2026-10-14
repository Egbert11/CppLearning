// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：Quiz #5 解答 —— 完整程序：读入一个整数，用 doubleNumber() 翻倍后打印。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           8
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-quiz5.cpp -o a

#include <iostream>

int doubleNumber(int x)
{
    return 2 * x;
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << doubleNumber(x) << '\n';

    return 0;
}
