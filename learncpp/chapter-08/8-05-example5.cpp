// 来源小节：8.5 Switch statement basics
// 示例说明：既没有 case 匹配、也没有 default —— 整个 switch 被跳过，继续执行 switch 之后的代码。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example5.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（x = 5）：
//   Hello

#include <iostream>

int main()
{
    switch (5) // no case matches and no default
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    } // execution continues here

    std::cout << "Hello\n";

    return 0;
}
