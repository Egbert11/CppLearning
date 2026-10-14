// 来源小节：8.9 Do while statements
// 示例说明：用 while 循环 + 非法初值（哨兵值 0）实现菜单至少显示一次
// 原文链接：https://www.learncpp.com/cpp-tutorial/do-while-statements/

#include <iostream>

int main()
{
    // selection must be declared outside while-loop, so we can use it later
    int selection {}; // value initialized to 0

    while (selection < 1 || selection > 4)
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}
