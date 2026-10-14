// 来源小节：8.3 Common if statement problems
// 示例说明：用显式花括号消除悬垂 else 的歧义——内层 else 绑内层 if，外层 else 绑外层 if。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example4.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0)
    {
        if (x <= 20)
            std::cout << x << " is between 0 and 20\n";
        else // attached to inner if statement
            std::cout << x << " is greater than 20\n";
    }
    else // attached to outer if statement
        std::cout << x << " is negative\n";

    return 0;
}
