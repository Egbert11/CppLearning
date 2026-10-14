// 来源小节：9.3 Common semantic errors in C++
// 示例说明：off-by-one 错误——本该用 <= 却用了 <，循环少运行一次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example5-broken.cpp -o a
// 预期输出：1 2 3 4   （而不是想要的 1 2 3 4 5）
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。

#include <iostream>

int main()
{
    for (int count{ 1 }; count < 5; ++count) // oops: should be count <= 5
        std::cout << count << ' ';

    std::cout << '\n';

    return 0;
}
