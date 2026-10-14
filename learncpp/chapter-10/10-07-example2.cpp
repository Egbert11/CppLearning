// 来源小节：10.7 Typedefs and type aliases
// 示例说明：Miles 与 Speed 都别名 long，编译器不会阻止在两者之间赋值——语法合法，
//           但语义上没有意义，说明类型别名不提供类型安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example2.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
using Miles = long;
using Speed = long;
// --- 原文示例片段结束 ---

int main()
{
    Miles distance{ 100 };
    Speed velocity{ 60 };

    distance = velocity; // 语法合法（都是 long），但语义上没有意义

    std::cout << distance << '\n';

    return 0;
}
