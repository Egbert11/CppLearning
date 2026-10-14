// 来源小节：3.5 More debugging tactics
// 示例说明：用 std::cerr 无条件地打印调试语句的原始程序。
//           调试结束后，这些语句必须被删除或注释掉——这正是本节要改进的地方。
// 原文链接：https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
//
// 预期输出（用户输入 4）：
//   main() called
//   getUserInput() called
//   Enter a number: 4
//   You entered: 4

#include <iostream>

int getUserInput()
{
    std::cerr << "getUserInput() called\n"; // 调试语句：写死在这里，调试完必须删除

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    std::cerr << "main() called\n"; // 调试语句

    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
