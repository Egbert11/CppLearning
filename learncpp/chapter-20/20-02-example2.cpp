// 来源小节：20.2 The stack and the heap
// 示例说明：函数调用栈的压栈/出栈轨迹。main() 先被压栈，
//           调用 foo() 时 foo()（含参数 x）被压到 main() 之上，返回时出栈。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/
// 说明：本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
int foo(int x)
{
    // b
    return x;
} // foo is popped off the call stack here

int main()
{
    // a
    foo(5); // foo is pushed on the call stack here
    // c

    return 0;
}
// --- 原文示例片段结束 ---

// Stack contents while the program is executing:
// a: main()
// b: foo() (including parameter x) on top of main()
// c: main()
