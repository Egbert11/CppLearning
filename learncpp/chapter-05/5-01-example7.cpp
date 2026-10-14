// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：带替换文本的对象式宏。预处理器会把宏名替换为替换文本，
//           因此它也算一种命名常量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
#define MY_NAME "Alex"
// --- 原文示例片段结束 ---

int main()
{
    // 预处理器会把下行的 MY_NAME 替换成 "Alex"
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
