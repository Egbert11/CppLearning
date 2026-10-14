// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：isEven() 的逐步化简——从 if/else 到一行 return。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建（测验 Q2 解答注解）。
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
// 版本 1：if/else 分别返回 true/false
bool isEvenV1(int x)
{
    if ((x % 2) == 0)
        return true;
    else
        return false;
}

// 版本 2：把比较结果存入 bool 变量后返回
bool isEvenV2(int x)
{
    bool isEven = (x % 2) == 0;
    return isEven;
}

// 版本 3：直接返回比较结果（最终写法）
bool isEvenV3(int x)
{
    return (x % 2) == 0;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << std::boolalpha;
    std::cout << "isEvenV1(4) = " << isEvenV1(4) << '\n';
    std::cout << "isEvenV2(5) = " << isEvenV2(5) << '\n';
    std::cout << "isEvenV3(4) = " << isEvenV3(4) << '\n';

    return 0;
}
