// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：本节 quiz 第 2 题解答——用 while 循环打印小写字母及其 ASCII 码。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example14-quiz.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（前几行）：
//   a 97
//   b 98
//   c 99
//   ...
//   z 122

#include <iostream>

int main()
{
    char myChar{ 'a' };
    while (myChar <= 'z')
    {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    }

    return 0;
}
