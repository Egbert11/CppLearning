// 来源小节：1.9 Introduction to literals and operators
// 示例说明：原文测验 1a–1c，体现运算符优先级（乘法先于加法）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/
//
// 编译：g++ -std=c++20 -Wall 1-09-example3.cpp -o example3

#include <iostream>

int main()
{
    std::cout << 3 + 4 << '\n';     // 7
    std::cout << 3 + 4 - 5 << '\n'; // 2
    std::cout << 2 + 3 * 4 << '\n'; // 14（先算 3 * 4 = 12，再算 2 + 12）

    return 0;
}
