// 来源小节：2.5 Introduction to local scope
// 示例说明：修正版 —— 把 val 改成 getValueFromUser() 内部的局部变量，函数不再需要参数。
//           预期交互（用户输入 4）：
//           Enter an integer: 4
//           4 doubled is: 8
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example10.cpp -o a

#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int val {}; // define val as a local variable
    std::cin >> val;

    return val;
}

int main()
{
    int x{ getValueFromUser() };

    std::cout << x << " doubled is: " << x * 2 << '\n';

    return 0;
}
