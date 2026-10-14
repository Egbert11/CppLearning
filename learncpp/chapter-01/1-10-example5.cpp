// 来源小节：1.10 Introduction to expressions
// 示例说明：原文测验第 3 题——打印 2 + 3，再计算并打印 y 与 z * x（输出 5、4、36）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
//
// 编译：g++ -std=c++20 -Wall 1-10-example5.cpp -o example5

#include <iostream>

int main()
{
    std::cout << 2 + 3 << '\n'; // 5

    int x{ 6 };
    int y{ x - 2 };
    std::cout << y << '\n'; // 4

    int z{};
    z = x;
    std::cout << z * x << '\n'; // 36

    return 0;
}
