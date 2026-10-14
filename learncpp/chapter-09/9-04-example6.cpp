// 来源小节：9.4 Detecting and handling errors
// 示例说明：使用哨兵值（sentinel value）——0.0 永远不可能是倒数的合法结果，
//           因此用它表示"无倒数"这一错误；返回带名字的常量以提升可读性。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example6.cpp -o a
// 预期输出：
//   0.5
//   0
//
// 本节代码为按原文描述重建。

#include <iostream>

constexpr double error_no_reciprocal{ 0.0 }; // could also be put in a namespace

// The reciprocal of x is 1/x
// returns 0.0 if x=0
double reciprocal(double x)
{
    if (x == 0.0)
        return error_no_reciprocal; // sentinel value signaling failure

    return 1.0 / x;
}

int main()
{
    std::cout << reciprocal(2.0) << '\n'; // 0.5
    std::cout << reciprocal(0.0) << '\n'; // 0 (the sentinel)

    return 0;
}
