// 来源小节：8.11 Break and continue
// 示例说明：对比无限循环中 break（跳出循环）与 return（结束整个函数）的行为
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 这是交互式程序，需要用户输入。

#include <iostream>

int breakOrReturn()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";
    return 0;
}

int main()
{
    int returnValue{ breakOrReturn() };
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';

    return 0;
}
