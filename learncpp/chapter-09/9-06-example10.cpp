// 来源小节：9.6 Assert and static_assert
// 示例说明：getInverse()——当 x 为 0.0 时返回 1.0/0.0，行为异常（会得到 inf），
//           用来引出"断言 vs. 错误处理"的讨论。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example10.cpp -o a
// 预期输出：inf
//
// 本节代码为按原文描述重建。

#include <iostream>

double getInverse(double x)
{
    return 1.0 / x; // if x is 0.0, this produces inf (a "bad" result)
}

int main()
{
    std::cout << getInverse(2.0) << '\n'; // 0.5
    std::cout << getInverse(0.0) << '\n'; // inf

    return 0;
}
