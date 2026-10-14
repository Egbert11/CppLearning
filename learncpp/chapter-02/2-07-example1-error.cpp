// 来源小节：2.7 Forward declarations and definitions
// 示例说明：原始程序 —— 在 add() 被定义之前就调用它，编译器按顺序读代码，找不到该标识符。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: 'add' was not declared in this scope   (Visual Studio: C3861: 'add': identifier not found)
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example1-error.cpp -o a   （会报错，属预期）

#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
