// 来源小节：8.11 Break and continue
// 示例说明：while (true) 无限循环，用户输入 0 时用 break 跳出
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 这是交互式程序，需要用户输入。

#include <iostream>

int main()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 0 to exit or any other integer to continue: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break;
    }

    std::cout << "We're out!\n";

    return 0;
}
