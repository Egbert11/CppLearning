// 来源小节：1.9 Introduction to literals and operators
// 示例说明：对比打印字面量 5 与变量 x 的值（原文完整程序）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/
//
// 编译：g++ -std=c++20 -Wall 1-09-example1.cpp -o example1

#include <iostream>

int main()
{
    std::cout << 5 << '\n'; // print the value of a literal

    int x { 5 };
    std::cout << x << '\n'; // print the value of a variable
    return 0;
}
