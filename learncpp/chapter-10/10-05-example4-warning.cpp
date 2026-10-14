// 来源小节：10.5 Arithmetic conversions
// 示例说明：比较运算的意外——-3 < 5u 为 false，因为 -3 被转成很大的无符号值，
//           比 5 大。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
//
// 编译：g++ -std=c++20 -Wall 10-05-example4.cpp -o a
// 预期输出：false
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // -3 will be converted to a large unsigned value, which is greater than 5
    std::cout << std::boolalpha << (-3 < 5u) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
