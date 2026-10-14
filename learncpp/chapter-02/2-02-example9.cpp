// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：违反 DRY 的程序 —— 两段几乎相同的输入代码分别初始化 x 和 y，然后打印它们的和。
//           预期交互（用户先输入 5 再输入 7）：
//           Enter an integer: 5
//           Enter another integer: 7
//           5 + 7 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example9.cpp -o a

#include <iostream>

int main()
{
    // Ask the user for two integers and have the user enter them
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
