// 来源小节：1.10 Introduction to expressions
// 示例说明：五个单行表达式及其求值结果：字面量、字符串字面量、变量、2 + 3、函数调用 five()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
//
// 编译：g++ -std=c++20 -Wall 1-10-example2.cpp -o example2
// 说明：这些是“表达式语句”，其计算结果被丢弃，gcc/Clang 可能对部分语句给出 -Wunused-value 警告。

#include <iostream>

int five()
{
    return 5;
}

int main()
{
    int x { 7 };

    // --- 原文示例片段 ---
    2;               // evaluates to the literal value 2
    "Hello world!";  // evaluates to the text "Hello world!"
    x;               // evaluates to the value of x
    2 + 3;           // evaluates to the value 5
    five();          // evaluates to the return value of five()
    // --- 原文示例片段结束 ---

    std::cout << x << '\n';
    return 0;
}
