// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：as-if 规则。x 和 y 是编译期常量，x + y 既可在编译期
//           求值，也可在运行期求值——编译器自行决定。
//           预期输出：4.6
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const double x { 1.2 };
    const double y { 3.4 };
    const double z { x + y }; // x + y may evaluate at runtime or compile-time
    // --- 原文示例片段结束 ---

    std::cout << z << '\n';

    return 0;
}
