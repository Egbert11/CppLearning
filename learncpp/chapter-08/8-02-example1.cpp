// 来源小节：8.2 If statements and blocks
// 示例说明：一个基本的 if-else 语句：判断读入的整数是否大于 10，并打印对应信息。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   输入 15 -> "15 is greater than 10"
//   输入 4  -> "4 is not greater than 10"

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x > 10)
        std::cout << x << " is greater than 10\n";
    else
        std::cout << x << " is not greater than 10\n";

    return 0;
}
