// 来源小节：8.3 Common if statement problems
// 示例说明：嵌套 if——注意原文指出这样不加块地嵌套是不好的风格。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0) // outer if statement
        // it is bad coding style to nest if statements this way
        if (x <= 20) // inner if statement
            std::cout << x << " is between 0 and 20\n";

    return 0;
}
