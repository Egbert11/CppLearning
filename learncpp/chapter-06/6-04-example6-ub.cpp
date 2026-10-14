// ============================================================
// 来源小节：6.4 Increment/decrement operators, and side effects
// 示例说明：实参求值顺序导致未定义行为——add(x, ++x) 中 x 既有普通求值
//           又有副作用，标准未定义实参求值顺序，结果可能是 11 或 12。
// 原文链接：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
// !! -ub：这是未定义行为演示（可编译）。Visual Studio 与 GCC 与 Clang 结果可能不同。
// ============================================================
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int value{ add(x, ++x) }; // undefined behavior: is this 5 + 6, or 6 + 6?
                              // It depends on whether the compiler evaluates the left or right argument first.

    std::cout << value << '\n'; // could be 11 or 12
    // --- 原文示例片段结束 ---

    return 0;
}
