// 来源小节：10.2 Floating-point and integral promotion
// 示例说明：引入一个以 int 为形参的函数。因为存在整型提升，所有更窄的整型实参
//           都能自动提升为 int，所以无需为每种类型各写一个重载版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/
//
// 编译：g++ -std=c++20 -Wall 10-02-example1.cpp -o a
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
    printInt(s); // numeric promotion of short to int

    printInt('a');  // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int

    return 0;
}
