// 来源小节：1.4 Variable assignment and initialization
// 示例说明：列表初始化不允许"窄化转换"，而拷贝/直接初始化会静默截断小数部分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 预期输出：
//   4
//   4
//
// ※※※ 说明 ※※※
// 原示例中的 `int w1 { 4.5 };` 是【编译错误】，为让本文件可通过编译，
// 该行以注释保留（见下方）。取消注释即会重现该编译错误。

#include <iostream>

int main()
{
    // An integer can only hold non-fractional values.
    // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
    // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.

    // int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion  <-- 取消注释将无法编译

    // --- 原文示例片段：拷贝/直接初始化会静默截断 ---
    int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
    int w3 (4.5);   // compiles: w3 direct-initialized to value 4
    // --- 原文示例片段结束 ---

    // The narrowing rule applies to initialization only, not to later assignment:
    // w1 = 4.5;       // okay: copy-assignment allows narrowing conversion of 4.5 to 4

    std::cout << w2 << '\n'; // prints 4
    std::cout << w3 << '\n'; // prints 4

    return 0;
}
