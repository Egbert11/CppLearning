// 来源小节：9.6 Assert and static_assert
// 示例说明：非 bouncer 版本——同样能工作，但错误处理与主逻辑分离、嵌套更深，
//           作者称其为 "strictly worse"（明显更差）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example3.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDivision(int x, int y)
{
    if (y != 0)
    {
        std::cout << static_cast<double>(x) / y;
    }
    else
    {
        std::cerr << "Error: Could not divide by zero\n";
        return; // bounce the user back to the caller
    }
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    printDivision(x, y);

    return 0;
}
