// 来源小节：4.10 Introduction to if statements
// 示例说明：用 bool 变量实现同样的零/非零判断。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    bool zero { (x == 0) };
    if (zero)
        std::cout << "The value is zero\n";
    if (!zero)
        std::cout << "The value is non-zero\n";

    return 0;
}
