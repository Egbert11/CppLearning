// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5a —— 前置声明只有两个参数，却用三个实参调用 add()，编译失败。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: too many arguments to function 'int add(int, int)'
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5a-error.cpp -o a   （会报错，属预期）

#include <iostream>
int add(int x, int y); // declaration has two parameters

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n'; // no matching 3-argument add() is visible
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
