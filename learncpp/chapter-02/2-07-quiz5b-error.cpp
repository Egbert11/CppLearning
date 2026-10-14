// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5b —— 前置声明只有两个参数，三参数的定义出现在调用之后（此时还不可见），编译失败。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: too many arguments to function 'int add(int, int)'
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5b-error.cpp -o a   （会报错，属预期）

#include <iostream>
int add(int x, int y); // declaration has two parameters

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n'; // the 3-parameter add() isn't visible yet
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
