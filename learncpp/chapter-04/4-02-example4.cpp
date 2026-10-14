// 来源小节：4.2 Void
// 示例说明：已弃用的 C 风格写法 —— 参数列表中的 void 表示该函数没有参数。
//           这在 C++ 中仍可编译，但这种用法已被弃用。
//           预期交互：读入一个整数并打印它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void/
//
// 编译：g++ -std=c++20 -Wall 4-02-example4.cpp -o a

#include <iostream>

int getValue(void) // void here means no parameters
{
    int x{};
    std::cin >> x;

    return x;
}

int main()
{
    std::cout << getValue() << '\n';
    return 0;
}
