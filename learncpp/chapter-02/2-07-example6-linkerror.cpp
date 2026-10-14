// 来源小节：2.7 Forward declarations and definitions
// 示例说明：只有前置声明、没有定义 —— 程序能通过编译，但链接时找不到 add() 的实现。
//           【预期链接错误】编译命令会成功编译，但链接阶段失败，错误类似：
//           error: undefined reference to 'add(int, int)'
//           （Visual Studio: LNK2001: unresolved external symbol ...）
//           本示例按原文意图保留“缺失定义”的写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example6-error.cpp -o a   （编译通过但链接失败，属预期）

#include <iostream>

int add(int x, int y); // forward declaration of add()

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

// note: No definition for function add
