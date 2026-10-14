// 来源小节：9.3 Common semantic errors in C++
// 示例说明：for 循环的关系运算符写反了——用了 > 而非 <，循环体一次都不执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example2-broken.cpp -o a
// 输入 5 时预期输出：（无输出，循环体从未运行）
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    for (int count{ 1 }; count > x; ++count) // oops: operator> means the loop body never runs
        std::cout << count << ' ';

    return 0;
}
