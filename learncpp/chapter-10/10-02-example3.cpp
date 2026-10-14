// 来源小节：10.2 Floating-point and integral promotion
// 示例说明：同一个取 int 形参的函数，分别接受 int、short、char、bool 实参——
//           后三者都经由整型提升变为 int（chars 打印为对应的整数值）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/
//
// 编译：g++ -std=c++20 -Wall 10-02-example3.cpp -o a
// 预期输出：
//   2
//   3
//   97
//   1
//
// 本节代码为按原文描述重建。

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    printInt(2);

    short s{ 3 }; // there is no short literal suffix, so we'll use a variable for this one
    printInt(s);  // numeric promotion of short to int

    printInt('a');  // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int

    return 0;
}
