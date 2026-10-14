// 来源小节：1.9 Introduction to literals and operators
// 示例说明：原文测验 1d（附加题）——赋值运算符有副作用，并返回其左操作数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/
//
// 编译：g++ -std=c++20 -Wall 1-09-example4.cpp -o example4

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 2 };
    std::cout << (x = 5) << '\n';
    // --- 原文示例片段结束 ---

    // x = 5 把 5 赋给 x，并返回 x，因此打印出 5。
    return 0;
}
