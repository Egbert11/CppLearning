// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5c —— 调用匹配的是两参数声明，但程序里只定义了三参数版本的 add()，
//           因此能编译，却在链接时找不到两参数 add() 的实现。
//           【预期链接错误】编译通过，但链接失败，错误类似：
//           error: undefined reference to 'add(int, int)'
//           本示例按原文意图保留该写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5c-linkerror.cpp -o a   （编译通过但链接失败，属预期）

#include <iostream>
int add(int x, int y); // declaration has two parameters, but only a 3-parameter version is defined

int main()
{
    std::cout << "3 + 4 = " << add(3, 4) << '\n'; // matches the 2-parameter declaration
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
