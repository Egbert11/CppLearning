// 来源小节：8.11 Break and continue
// 示例说明：最多读取 10 个数并求和，用户输入 0 时用 break 提前退出循环
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 这是交互式程序，需要用户输入。样例运行见 .md 文件。

#include <iostream>

int main()
{
    int sum{ 0 };

    // Allow the user to enter up to 10 numbers
    for (int count{ 0 }; count < 10; ++count)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break; // exit the loop now

        // otherwise add number to our sum
        sum += num;
    }

    // execution will continue here after the break
    std::cout << "The sum of all the numbers you entered is: " << sum << '\n';

    return 0;
}
