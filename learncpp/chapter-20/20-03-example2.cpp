// 来源小节：20.3 Recursion
// 示例说明：带终止条件（base case）的递归。递归调用之前的语句按正向顺序执行，
//           递归调用之后的语句按反向顺序执行（栈展开）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   push 5
//   push 4
//   push 3
//   push 2
//   push 1
//   pop 1
//   pop 2
//   pop 3
//   pop 4
//   pop 5

#include <iostream>

// --- 原文示例片段 ---
void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1); // countDown() calls itself recursively

    std::cout << "pop " << count << '\n';
}

int main()
{
    countDown(5);

    return 0;
}
// --- 原文示例片段结束 ---
