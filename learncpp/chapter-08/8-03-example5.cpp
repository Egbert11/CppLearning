// 来源小节：8.3 Common if statement problems
// 示例说明：把嵌套 if 展平（flatten）——用 else if 链代替嵌套，可读性更好、更不易出错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example5.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";

    return 0;
}
