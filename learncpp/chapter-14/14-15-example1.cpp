// ============================================================
// 来源小节：14.15 Class initialization and copy elision
// 示例说明：基础类型的六种初始化形式（回顾）——默认、拷贝、直接、直接列表、
//           拷贝列表、值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/
// 备注：本节代码为按原文描述忠实重建（原文为语法片段）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 1）---
    int a;         // no initializer (default initialization)
    int b = 5;     // initializer after equals sign (copy initialization)
    int c( 6 );    // initializer in parentheses (direct initialization)
    int d { 7 };   // initializer in braces (direct list initialization)
    int e = { 8 }; // initializer in braces after equals sign (copy list initialization)
    int f {};      // initializer is empty braces (value initialization)
    // --- 原文示例片段结束 ---

    // 原文这些变量未被使用；这里打印出来以说明各初始化形式的取值。
    std::cout << b << ' ' << c << ' ' << d << ' '
              << e << ' ' << f << '\n';
    (void)a; // a 默认初始化，值不确定，不使用

    return 0;
}

// 预期输出：
// 5 6 7 8 0
