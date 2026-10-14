// 来源小节：8.11 Break and continue
// 示例说明：用 bool 标志控制循环退出（不使用 break）
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 这是交互式程序，需要用户输入。

#include <iostream>

int main()
{
    int count{ 0 }; // count how many times the loop iterates
    bool keepLooping { true }; // controls whether the loop ends or not
    while (keepLooping)
    {
        std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e')
            keepLooping = false;
        else
        {
            ++count;
            std::cout << "We've iterated " << count << " times\n";
        }
    }

    return 0;
}
