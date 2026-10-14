// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：const 返回值。返回类型加 const 语法上允许，但对基本
//           类型而言该限定符会被忽略（可能引发编译器警告），通常无意义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
const int getValue()
{
    return 5;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << getValue() << '\n';

    return 0;
}
