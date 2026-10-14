// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：用 static_cast<double> 把 x 转成 double，得到浮点除法结果 2.5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example4.cpp -o a
// 预期输出：2.5
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    int x{ 10 };
    int y{ 4 };

    // --- 原文示例片段 ---
    // static cast x to a double so we get floating point division
    std::cout << static_cast<double>(x) / y << '\n'; // prints 2.5
    // --- 原文示例片段结束 ---

    return 0;
}
