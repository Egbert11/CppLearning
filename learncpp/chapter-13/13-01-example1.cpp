// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 示例说明：定义基本类型（fundamental type）的变量——基本类型是 C++ 核心
//           语言的一部分，不需要任何定义即可直接使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 备注：本节代码为按原文描述忠实重建。原文片段未给变量加初始化/属性，
//       此处为消除 -Wunused-variable 警告加了 [[maybe_unused]]，
//       语义与原文一致。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] int x;    // define variable of fundamental type 'int'
    [[maybe_unused]] double d; // define variable of fundamental type 'double'
    // --- 原文示例片段结束 ---

    return 0;
}
