// 来源小节：20.2 The stack and the heap
// 示例说明：通过无限递归造成栈溢出。每次调用 eatStack() 都压入一个栈帧，
//           而 eatStack() 从不返回给调用者，栈空间最终耗尽。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/
// 说明：本节代码为按原文描述重建。
// 预期行为：先不断打印计数器，然后崩溃（栈溢出）。
//   - 原文作者在 Windows 10 + Visual Studio Community 上的观察：
//       debug 模式约 4848 次调用后崩溃，release 模式约 128679 次调用后崩溃；
//       g++/Clang 上的崩溃点取决于栈大小，结果是实现相关的。
//   - 本示例**请勿运行**，仅用来说明问题。

#include <iostream>

// --- 原文示例片段 ---
int g_counter{ 0 };

void eatStack()
{
    std::cout << ++g_counter << ' ';

    // We use a conditional here to avoid compiler warnings about infinite recursion
    if (g_counter > 0)
        eatStack(); // note that eatStack() calls itself

    // Needed to prevent compiler from doing tail-call optimization
    std::cout << "hi";
}

int main()
{
    eatStack();

    return 0;
}
// --- 原文示例片段结束 ---
