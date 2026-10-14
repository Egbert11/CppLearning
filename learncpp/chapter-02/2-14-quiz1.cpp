// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 1：在单个文件 main.cpp 中实现——让用户输入两个整数，求和并打印结果。
//        要求用三个函数组织：readNumber() 读取并返回一个整数；
//        writeAnswer() 接收一个参数、无返回值，负责打印结果；main() 把它们串起来。
// 提示：不需要单独的加法函数，直接用 operator+；readNumber() 需要被调用两次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 2-14-quiz1.cpp -o quiz1

#include <iostream>

int readNumber()
{
    std::cout << "Enter a number to add: ";
    int x {};
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}

int main()
{
    int x { readNumber() };
    int y { readNumber() };

    writeAnswer(x + y); // using operator+ to pass the sum of x and y to writeAnswer()

    return 0;
}
