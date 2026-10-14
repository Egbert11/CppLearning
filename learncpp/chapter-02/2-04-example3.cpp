// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：在 printDouble() 里加上局部变量 int num{}; —— 程序能编译了，
//           但这个 num 与 main() 里的 num 无关，永远是 0。
//           预期输出（无论用户输入什么）：0 doubled is: 0
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example3.cpp -o a

#include <iostream>

void printDouble()
{
    int num{}; // this num is a local variable, it is zero
    std::cout << num << " doubled is: " << num * 2 << '\n'; // always prints: 0 doubled is: 0
}

int main()
{
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;

    printDouble(); // the user's value in main's num never reaches printDouble()

    return 0;
}
