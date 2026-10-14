// 来源小节：1.6 Uninitialized variables and undefined behavior
// 示例说明：把未初始化的变量按引用传给一个什么都不做的函数，
//           "骗过"编译器、让它以为该变量被使用了，从而让程序得以编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/
//
// ※※※ 注意 ※※※
// 本程序可编译通过，但【输出是未定义的】（读取未初始化的变量是未定义行为）。
// 原文借此说明：有时程序"能编译、看起来在跑"，并不代表它没有未定义行为。

#include <iostream>

void doNothing(int&) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}

int main()
{
    // uninitialized variable
    int x;

    doNothing(x); // make the compiler think we're assigning a value to this variable

    std::cout << x << '\n'; // who knows what we'll get, because x is uninitialized

    return 0;
}
