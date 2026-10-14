// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：直接把表达式 5 + 3 作为实参传给函数，省掉临时变量。
//           当函数接受右值时，这种替换总是可行的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

void printValue(int value)
{
    std::cout << value << '\n';
}

int main()
{
    // --- 原文示例片段（原 Example 4）---
    printValue(5 + 3);
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 8
