// 来源小节：1.6 Uninitialized variables and undefined behavior
// 示例说明：打印 sizeof(int)，用于演示"实现定义行为"（结果随平台/实现而变）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/
//
// 预期输出：通常是 4，有时是 2（原文说明）。该结果由具体实现决定，属实现定义行为。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << sizeof(int) << '\n'; // print how many bytes of memory an int value takes
    // --- 原文示例片段结束 ---

    return 0;
}
