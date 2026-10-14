// 来源小节：8.4 Constexpr if statements
// 示例说明：普通 if 的条件是常量表达式，else 分支永远不可能执行——但仍在运行期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/
//
// 编译：g++ -std=c++20 -Wall 8-04-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   Gravity is normal.

#include <iostream>

int main()
{
    constexpr double gravity{ 9.8 };

    // reminder: low-precision floating point literals of the same type can be tested for equality
    if (gravity == 9.8) // constant expression, always true
        std::cout << "Gravity is normal.\n";   // will always be executed
    else
        std::cout << "We are not on Earth.\n"; // will never be executed

    return 0;
}
