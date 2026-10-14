// 来源小节：9.1 Introduction to testing your code
// 示例说明：比较两个整数的程序，含大于 / 小于 / 等于三个分支。用来展示
//           "用户输入 + 条件分支" 会如何把可能的执行路径成倍放大，使穷举测试不可行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
//
// 编译：g++ -std=c++20 -Wall 9-01-example1.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';  // case 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n';     // case 2
    else
        std::cout << x << " is equal to " << y << '\n';      // case 3
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    compare(x, y);

    return 0;
}
