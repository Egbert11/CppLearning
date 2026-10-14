// 来源小节：20.2 The stack and the heap
// 示例说明：栈溢出（stack overflow）。在栈上声明一个 10000000 个 int 的局部数组
//           （约 40MB，远超栈上限），程序会因访问违规而崩溃。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/
// 说明：本节代码为按原文描述重建。
// 预期行为：崩溃，而不是正常输出。
//   - 在 Windows/Visual Studio 上原文报告的输出是：
//       HelloWorld.exe (process 15916) exited with code -1073741571.
//     （-1073741571 的十六进制是 c0000005，即 Windows 的访问违规代码），"hi" 根本不会打印。
//   - 在 g++/Clang（Unix 或 MSYS2）上通常表现为 segmentation fault。
//   - 本示例**请勿运行**，仅用来说明问题；栈的大小默认在 VS 上约 1MB、在 g++/Clang 上最大约 8MB。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int stack[10000000]; // this array is too large to be allocated on the stack
    std::cout << "hi" << stack[0]; // we'll use stack[0] here so the compiler won't optimize the array away
    // --- 原文示例片段结束 ---

    return 0;
}
