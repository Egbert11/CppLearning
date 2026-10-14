// 来源小节：10.2 Floating-point and integral promotion
// 示例说明：浮点提升——形参为 double 的函数既接受 double 实参（无需转换），
//           也接受 float 实参（float 被提升为 double）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/
//
// 编译：g++ -std=c++20 -Wall 10-02-example2.cpp -o a
// 预期输出：
//   5
//   4
//
// 本节代码为按原文描述重建。

#include <iostream>

void printDouble(double d)
{
    std::cout << d << '\n';
}

int main()
{
    printDouble(5.0);  // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    return 0;
}
