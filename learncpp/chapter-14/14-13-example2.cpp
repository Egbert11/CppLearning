// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：add() 直接返回表达式 x + y，去掉只用一次的中间变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
int add(int x, int y)
{
    return x + y; // just return x + y directly
}

int main()
{
    std::cout << add(5, 3) << '\n';

    return 0;
}

// 预期输出：
// 8
