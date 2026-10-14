// 来源小节：1.4 Variable assignment and initialization
// 示例说明：未使用变量的警告，以及用 C++17 的 [[maybe_unused]] 属性抑制该警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 预期输出：
//   5
//   3.14159
//   1.61803
//   3.14159
//   1.61803
//
// 说明：unusedVar 与 gravity 被定义却未被使用，g++ -Wall 会给出 "unused variable" 警告
// （这正是原示例要演示的现象）；而带 [[maybe_unused]] 的变量即使未使用也不会警告。

#include <iostream>

int main()
{
    // --- 原文示例片段：定义了但未使用的变量（会产生 unused variable 警告）---
    int unusedVar { 5 }; // variable defined, but not used anywhere
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：通过"使用"变量来修复警告 ---
    int x { 5 };
    std::cout << x << '\n'; // variable now used somewhere
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：复制来的数值中，可能有一个未被使用 ---
    double pi { 3.14159 };
    double gravity { 9.8 };
    double phi { 1.61803 };

    std::cout << pi << '\n';  // pi is used
    std::cout << phi << '\n'; // phi is used
    // gravity 未被使用，编译器可能给出警告
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：使用 [[maybe_unused]]（C++17）消除未使用变量的警告 ---
    [[maybe_unused]] double pi2 { 3.14159 };  // Don't complain if pi2 is unused
    [[maybe_unused]] double gravity2 { 9.8 }; // Don't complain if gravity2 is unused
    [[maybe_unused]] double phi2 { 1.61803 }; // Don't complain if phi2 is unused

    std::cout << pi2 << '\n';
    std::cout << phi2 << '\n';
    // The compiler will no longer warn about gravity2 not being used
    // --- 原文示例片段结束 ---

    return 0;
}
