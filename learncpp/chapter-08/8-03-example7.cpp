// 来源小节：8.3 Common if statement problems
// 示例说明：空语句（null statement）——"由单个分号组成的表达式语句"，什么都不做。
//           这里演示合法使用：条件成立时故意不做任何事。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example7.cpp -o a
//
// 本节代码为按原文描述重建（原文为片段，此处补上 main 与变量）。

#include <iostream>

int main()
{
    int x{ 15 };

    // --- 原文示例片段 ---
    if (x > 10)
        ; // this is a null statement
    // --- 原文示例片段结束 ---

    std::cout << "done\n";

    return 0;
}
