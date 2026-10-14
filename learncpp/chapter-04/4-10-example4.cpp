// 来源小节：4.10 Introduction to if statements
// 示例说明：把同一程序改写为 if-else。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 预期输出：
//   Enter an integer: 0
//   The value is zero
//
//   Enter an integer: 5
//   The value is non-zero

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";
    else
        std::cout << "The value is non-zero\n";

    return 0;
}
