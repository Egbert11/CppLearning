// 来源小节：7.12 Scope, duration, and linkage summary
// 示例说明：原文以表格逐条列举声明片段，并非完整程序。此文件把这些类别整合成一个可编译示例，
//           用 "// --- 原文示例片段 ---" 标出各片段边界。每个片段对应原文表格中的一行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/
//
// 本节示例为按原文描述重建（原文以表格列出各声明片段，未给出可运行程序）。
// 预期输出：
// (block scope) local x = 1
// (block scope) static local s_x = 2
// (block scope) dynamic x = 3
// (function param) x = 4
// (global scope) gExternal = 20
// (global scope) gInternal = 10
// (global scope) gInternalConstexpr = 1
// (global scope) gExternalConst = 2
// (global scope) gInline = 30

#include <iostream>

// --- 原文示例片段：int g_x;  （全局作用域 / 静态持久期 / 外部链接）---
int gExternal{ 20 };

// --- 原文示例片段：static int g_x;  （全局作用域 / 静态持久期 / 内部链接）---
static int gInternal{ 10 };

// --- 原文示例片段：constexpr int g_x { 1 };  （全局作用域 / 静态持久期 / 内部链接，必须初始化）---
constexpr int gInternalConstexpr{ 1 };

// --- 原文示例片段：extern const int g_x { 1 };  （全局作用域 / 静态持久期 / 外部链接，必须初始化）---
extern const int gExternalConst{ 2 };

// --- 原文示例片段：inline int g_x;  （C++17；全局作用域 / 静态持久期 / 外部链接）---
inline int gInline{ 30 };

// --- 原文示例片段：void foo(int x)  （函数形参：块作用域 / 自动持久期 / 无链接）---
void foo(int x)
{
    std::cout << "(function param) x = " << x << '\n';
}

int main()
{
    // --- 原文示例片段：int x;  （局部变量：块作用域 / 自动持久期 / 无链接）---
    int x{ 1 };
    std::cout << "(block scope) local x = " << x << '\n';

    // --- 原文示例片段：static int s_x;  （静态局部变量：块作用域 / 静态持久期 / 无链接）---
    static int s_x{ 2 };
    std::cout << "(block scope) static local s_x = " << s_x << '\n';

    // --- 原文示例片段：int* x { new int{} };  （动态局部变量：块作用域 / 动态持久期 / 无链接）---
    int* dx{ new int{ 3 } };
    std::cout << "(block scope) dynamic x = " << *dx << '\n';
    delete dx; // 动态持久期由程序员负责销毁

    foo(4);

    std::cout << "(global scope) gExternal = " << gExternal << '\n';
    std::cout << "(global scope) gInternal = " << gInternal << '\n';
    std::cout << "(global scope) gInternalConstexpr = " << gInternalConstexpr << '\n';
    std::cout << "(global scope) gExternalConst = " << gExternalConst << '\n';
    std::cout << "(global scope) gInline = " << gInline << '\n';

    return 0;
}
