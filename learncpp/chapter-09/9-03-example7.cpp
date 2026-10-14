// 来源小节：9.3 Common semantic errors in C++
// 示例说明：浮点精度不足——float 无法精确表示 0.123456789，被舍入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example7.cpp -o a
// 预期输出：0.123457
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    float f{ 0.123456789f }; // only 7 digits of precision are guaranteed
    // --- 原文示例片段结束 ---

    std::cout << f << '\n';

    return 0;
}
