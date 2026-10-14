// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：用直接列表初始化的临时量 double{x} 做转换：int 为 32 位时没问题，
//           若 int 是 64 位则会因窄化而编译失败。（对应原文示例 13）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
//
// 编译：g++ -std=c++20 -Wall 10-06-example8.cpp -o a
// 预期输出：2.5
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    int x{ 10 };
    int y{ 4 };

    // --- 原文示例片段 ---
    std::cout << double{ x } / y << '\n'; // okay if int is 32-bit, narrowing if x is 64-bit
    // --- 原文示例片段结束 ---

    return 0;
}
