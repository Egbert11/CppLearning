// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：add() 用中间变量 sum 保存 x + y 再返回——变量只用一次，
//           增加了不必要的复杂度（有时便于调试）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
int add(int x, int y)
{
    int sum{ x + y }; // 变量只使用一次
    return sum;
}

int main()
{
    std::cout << add(5, 3) << '\n';

    return 0;
}

// 预期输出：
// 8
