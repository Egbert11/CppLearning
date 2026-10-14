// 来源小节：8.2 If statements and blocks
// 示例说明：与示例 11 等价的 if-if 写法——因为每个分支都 return，可以省掉 else。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example12.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

char getFirstMatchingChar(bool a, bool b, bool c)
{
    if (a)
        return 'a';
    if (b)
        return 'b';
    if (c)
        return 'c';

    return 0;
}

int main()
{
    std::cout << getFirstMatchingChar(true, true, true) << '\n';   // a
    std::cout << getFirstMatchingChar(false, true, true) << '\n';  // b
    std::cout << getFirstMatchingChar(false, false, true) << '\n'; // c

    return 0;
}
