// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：在判断中对比较结果取反。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 50 };
    bool tooLarge { x > 100 }; // tooLarge is false

    if (!tooLarge)
        std::cout << x << " is not too large\n";
    else
        std::cout << x << " is too large\n";
    // --- 原文示例片段结束 ---

    return 0;
}
