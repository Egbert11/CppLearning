// 来源小节：10.7 Typedefs and type aliases
// 示例说明：用 using 为 double 定义别名 Distance，并用它声明变量、作为函数形参，
//           最后打印。（对应原文示例 1~4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example1.cpp -o a
// 预期输出：3.4
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
using Distance = double; // define Distance as an alias for type double
// --- 原文示例片段结束 ---

void printDistance(Distance distance) // Distance is some defined type
{
    std::cout << distance << '\n';
}

int main()
{
    // --- 原文示例片段 ---
    Distance milesToDestination{ 3.4 }; // defines a variable of type double
    // --- 原文示例片段结束 ---

    std::cout << milesToDestination << '\n'; // 3.4
    printDistance(milesToDestination);       // 3.4

    return 0;
}
