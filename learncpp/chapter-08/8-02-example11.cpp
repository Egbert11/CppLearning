// 来源小节：8.2 If statements and blocks
// 示例说明：用 if / else if 链 + return，返回第一个匹配条件对应的字符。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example11.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

char getFirstMatchingChar(bool a, bool b, bool c)
{
    if (a)
        return 'a';
    else if (b)
        return 'b';
    else if (c)
        return 'c';

    return 0;
}

int main()
{
    std::cout << getFirstMatchingChar(true, true, true) << '\n';   // a
    std::cout << getFirstMatchingChar(false, true, true) << '\n';  // b
    std::cout << getFirstMatchingChar(false, false, true) << '\n'; // c
    std::cout << getFirstMatchingChar(false, false, false) << '\n';// (非打印字符)

    return 0;
}
