// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：C 风格转换 (double)x 与函数式转换 double(x) 把 x 转成 double，从而
//           做浮点除法。（对应原文示例 4、5；此处仅为演示，实际应改用 static_cast。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example2.cpp -o a
// 预期输出：2.5 和 2.5
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    int x{ 10 };
    int y{ 4 };

    // --- 原文示例片段（示例 4） ---
    std::cout << (double)x / y << '\n'; // C-style cast of x to double
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（示例 5） ---
    std::cout << double(x) / y << '\n'; // function-style cast of x to double
    // --- 原文示例片段结束 ---

    return 0;
}
