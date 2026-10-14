// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：用 operator! 改写的 isEven()（测验解答）——对余数取非。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
bool isEven(int x)
{
    return !(x % 2);
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << std::boolalpha;
    for (int x : { 4, 5, -3, 0 })
        std::cout << x << " is even: " << isEven(x) << '\n';

    return 0;
}
