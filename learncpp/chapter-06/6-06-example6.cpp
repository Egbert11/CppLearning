// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：优先级意外。`10 - x > y ? x : y` 实际解析为 `((10 - x) > y) ? x : y`，
//           给出 2，而非未加括号时直觉以为的 8。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 2 };
    int y{ 1 };

    int z { 10 - x > y ? x : y }; // parses as ((10 - x) > y) ? x : y
    std::cout << z << '\n';       // prints 2, not 8
    // --- 原文示例片段结束 ---

    return 0;
}
