// 来源小节：9.3 Common semantic errors in C++
// 示例说明：条件逻辑错误——本想用 operator>，却写成了 operator>=。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example1-broken.cpp -o a
// 输入 5 时预期输出：5 is greater than 5
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践），能编译但输出不符合意图。

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 5) // oops, we used operator>= instead of operator>
        std::cout << x << " is greater than 5\n";
    else
        std::cout << x << " is not greater than 5\n";

    return 0;
}
