// 来源小节：4.10 Introduction to if statements
// 示例说明：基本 if 语句——若输入的整数为 0 则打印提示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 预期输出：
//   Enter an integer: 0
//   The value is zero

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";

    return 0;
}
