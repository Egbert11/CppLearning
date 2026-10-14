// 来源小节：8.2 If statements and blocks
// 示例说明：if-else 与 if-if 的区别：用三个布尔参数演示，if-else 只执行第一个为真的分支，
//           而 if-if 会执行所有为真的分支。
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example10.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文说明：ifelse(false, true, true) 只打印 "b"，而 ifif(false, true, true) 打印 "b" 和 "c"。

#include <iostream>

void ifelse(bool a, bool b, bool c)
{
    if (a)      // only if a is true
        std::cout << 'a';
    else if (b) // only if a is false and b is true
        std::cout << 'b';
    else if (c) // only if a and b are false and c is true
        std::cout << 'c';

    std::cout << '\n';
}

void ifif(bool a, bool b, bool c)
{
    if (a) // if a is true
        std::cout << 'a';
    if (b) // if b is true
        std::cout << 'b';
    if (c) // if c is true
        std::cout << 'c';

    std::cout << '\n';
}

int main()
{
    ifelse(false, true, true); // prints "b" (only the first true condition runs)
    ifif(false, true, true);   // prints "bc" (all true conditions run)

    return 0;
}
