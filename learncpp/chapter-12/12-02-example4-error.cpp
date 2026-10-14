// ============================================================
// 来源小节：12.2 Value categories (lvalues and rvalues)
// 示例说明：类型检查——把一个字符串字面量传给接收 int 的函数，编译器
//           因类型不匹配而报错。这演示"编译期类型检查"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
// !! -error：预期编译失败，勿修复。
//   预期错误：无法把 const char[4] 转换为 int（no matching function / conversion）。
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 4）---
void print(int x)
{
    std::cout << x << '\n';
}

int main()
{
    print("foo"); // error: print() expects an int argument, but we passed a string literal

    return 0;
}
// --- 原文示例片段结束 ---
