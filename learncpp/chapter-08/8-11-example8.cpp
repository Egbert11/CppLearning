// 来源小节：8.11 Break and continue
// 示例说明：与示例 7 行为相同，但用单个 break 简化，去掉多余的 bool 变量
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 这是交互式程序，需要用户输入。

#include <iostream>

int main()
{
    int count{ 0 }; // count how many times the loop iterates
    while (true) // loop until user terminates
    {
        std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e')
            break;

        ++count;
        std::cout << "We've iterated " << count << " times\n";
    }

    return 0;
}
