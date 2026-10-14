// 来源小节：1.10 Introduction to expressions
// 示例说明：含表达式的定义语句、结果被丢弃的表达式语句，以及子表达式示例。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
//
// 编译：g++ -std=c++20 -Wall 1-10-example4.cpp -o example4

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 2 + 3 }; // 语句，其中 2 + 3 是表达式（表达式本身不带分号）
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（表达式语句，结果被丢弃）---
    2 * 3; // 6 is calculated and discarded
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（子表达式示例）---
    2;         // 2 是一个表达式
    2 + 3;     // 2 + 3 是一个表达式，其中 2 和 3 是它的子表达式
    int y {};
    y = 4 + 5; // y 和 4 + 5 都是子表达式，4 和 5 是 4 + 5 的子表达式
    // --- 原文示例片段结束 ---

    std::cout << x << ' ' << y << '\n';
    return 0;
}
