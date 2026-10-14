// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：两个操作数找不到公共类型——编译失败（预期）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// !! -error：预期编译失败，勿修复。
//   预期错误：int 与 const char* 之间没有公共类型（operands to ?: have different types）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int x{ 5 };

    // error: operands to '?:' have different types 'const int' and 'const char*'
    std::cout << ((x != 5) ? x : "x is 5");
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
