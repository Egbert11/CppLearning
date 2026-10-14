// 来源小节：9.2 Code coverage
// 示例说明：一次 foo(1, 0) 调用覆盖了函数里全部语句，却只覆盖了 if 的一个分支
//           （true 分支未执行），用来演示"语句全覆盖 ≠ 分支全覆盖"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/code-coverage/
//
// 编译：g++ -std=c++20 -Wall 9-02-example1.cpp -o a
// 预期输出：1
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
int foo(int x, int y)
{
    int z{ y }; // statement 1
    if (x > y)  // statement 2 (branch point)
        z = x;  // statement 3

    return z;   // statement 4
}
// --- 原文示例片段结束 ---

int main()
{
    // This call covers all statements (1, 2, 3 is skipped, 4)
    // but only the false branch of the if.
    std::cout << foo(1, 0) << '\n';

    return 0;
}
