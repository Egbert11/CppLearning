// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：用 if-else 尝试定义 constexpr 变量——编译失败（预期）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// !! -error：预期编译失败，勿修复。
//   预期错误：classSize 在 if/else 块外未定义（out of scope / undeclared）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr bool inBigClassroom { false };

    // 每个分支里声明 classSize，块结束即销毁，块外不可见
    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };

    // error: 'classSize' was not declared in this scope
    std::cout << "The class size is: " << classSize << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
