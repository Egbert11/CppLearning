// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：要求编译期求值 vs 可选编译期求值的上下文对比。
//           const int 的初始化式必须编译期求值；
//           int（非常量）的初始化式可编译期也可运行期求值。
//           预期输出：7 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const int x { 3 + 4 }; // constant expression 3 + 4 must be evaluated at compile-time
    int y { 3 + 4 };       // constant expression 3 + 4 may be evaluated at compile-time (or runtime)
    // --- 原文示例片段结束 ---

    std::cout << x << ' ' << y << '\n';

    return 0;
}
