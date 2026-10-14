// 来源小节：8.7 Goto statements
// 示例说明：用向后 goto 反复提示用户，直到输入一个非负数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/goto-statements/
//
// 编译：g++ -std=c++20 -Wall 8-07-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文示例运行：
//   Enter a non-negative number: -4
//   Enter a non-negative number: 4
//   The square root of 4 is 2

#include <iostream>
#include <cmath> // for sqrt() function

int main()
{
    double x{};
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // this is the goto statement

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
    return 0;
}
