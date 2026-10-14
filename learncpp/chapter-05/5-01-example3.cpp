// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：const 变量必须初始化，且初始化后不能再次赋值。
//           原文用两个错误写法演示；此处把会编译失败的语句以
//           注释保留，并给出可编译的正确写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（错误写法）---
    // const double gravity; // error: constant variables must be initialized
    // gravity = 9.9;        // error: can't modify a const variable
    // --- 原文示例片段结束 ---

    // 正确写法：定义时即初始化
    const double gravity { 9.8 };
    std::cout << gravity << '\n';

    return 0;
}
