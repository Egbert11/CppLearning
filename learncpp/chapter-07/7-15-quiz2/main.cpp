// 来源小节：7.x Chapter 7 summary and quiz（测验第 2 题）
// 示例说明：题目给定的 main.cpp 原样保留 —— 读取班级人数并与 Constants::maxClassSize 比较。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
//
// 本节示例为按原文描述重建（对应原文 Quiz Question #2 的 main.cpp）。需交互输入。
// 示例输出（输入 40 时）：How many students are in your class? 40
//                        There are too many students in this class
// 示例输出（输入 30 时）：How many students are in your class? 30
//                        This class isn't too large
// 编译：g++ -std=c++20 -Wall 7-15-quiz2/main.cpp -o main

#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "How many students are in your class? ";
    int students{};
    std::cin >> students;

    if (students > Constants::maxClassSize)
        std::cout << "There are too many students in this class\n";
    else
        std::cout << "This class isn't too large\n";

    return 0;
}
