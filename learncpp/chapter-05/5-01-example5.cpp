// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：const 函数形参。形参声明为 const，无需写初始化式，
//           调用实参就是它的初始化式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
void printInt(const int x) // x is a const value parameter
{
    std::cout << x << '\n';
}

int main()
{
    printInt(5); // 5 used as initializer for x
    printInt(6); // 6 used as initializer for x

    return 0;
}
// --- 原文示例片段结束 ---
