// 来源小节：4.10 Introduction to if statements
// 示例说明：用两条独立的 if 分别判断 0 与非 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";
    if (x != 0)
        std::cout << "The value is non-zero\n";

    return 0;
}
