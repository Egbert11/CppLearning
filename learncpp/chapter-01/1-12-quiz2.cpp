// 来源小节：1.x Chapter 1 summary and quiz（官方编号 1.x）
// 题目：第 2 题——什么是未定义行为（undefined behavior）？
// 解答：当程序员做了 C++ 语言没有明确规定的事情时，就会发生未定义行为。
//       其后果范围很广：可能崩溃、可能得到错误结果，甚至可能表面上正常工作。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/
//
// 说明：下面“读取未初始化变量”的语句属于未定义行为，为安全起见以注释保留，
//       不真正执行，因此本文件只演示“正确初始化”的做法。
//
// 编译：g++ -std=c++20 -Wall 1-12-quiz2.cpp -o quiz2

#include <iostream>

int main()
{
    // 未定义行为示例（原文演示，未初始化变量的值是不确定的）：
    // int x;              // uninitialized variable
    // std::cout << x;     // undefined behavior: reading an uninitialized variable

    // 正确做法：始终初始化变量
    int x{};               // value-initialization：x 被置为 0
    std::cout << x << '\n';

    return 0;
}
