// 来源小节：9.6 Assert and static_assert
// 示例说明：bouncer pattern（门卫模式）——把前置条件 y != 0 放在函数最前面检查，
//           不满足就提前 return 回到调用者，从而避免深层嵌套。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example2.cpp -o a
// 这是交互式程序，需要用户输入两个整数。
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDivision(int x, int y)
{
    if (y == 0) // handle the error up front
    {
        std::cerr << "Error: Could not divide by zero\n";
        return; // bounce the user back to the caller
    }

    // We now know that y != 0
    std::cout << static_cast<double>(x) / y;
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
