// 来源小节：8.9 Do while statements
// 示例说明：同一菜单逻辑改用 do-while 实现（既无魔术数字，也无额外变量）
// 原文链接：https://www.learncpp.com/cpp-tutorial/do-while-statements/

#include <iostream>

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection {};

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection < 1 || selection > 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}
