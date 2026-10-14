// 来源小节：4.10 Introduction to if statements
// 示例说明：串联 if-else，判断输入为正、负还是零。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 预期输出：
//   Enter an integer: 4
//   The value is positive
//
//   Enter an integer: -3
//   The value is negative
//
//   Enter an integer: 0
//   The value is zero

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x > 0)
        std::cout << "The value is positive\n";
    else if (x < 0)
        std::cout << "The value is negative\n";
    else
        std::cout << "The value is zero\n";

    return 0;
}
