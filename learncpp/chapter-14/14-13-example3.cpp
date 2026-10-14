// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：把结果存入变量 sum 后再传给函数——同样因为只用一次而显得多余。
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
    // --- 原文示例片段（原 Example 3）---
    int sum{ 5 + 3 };
    printValue(sum);
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 8
