// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：用 != 实现逻辑 XOR（对 bool 成立，且可链式），
//           非 bool 操作数需 static_cast<bool> 或双重 !! 转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
// 备注：本节代码为按原文描述忠实重建。
//       链式 `a != b != c` 预期产生 -Wparentheses 警告（建议加括号），属故意演示。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    bool a{ true };
    bool b{ false };
    bool c{ true };

    if (a != b) // a XOR b, assuming a and b are bool
        std::cout << "a != b -> true (a XOR b)\n";

    if (a != b != c) // a XOR b XOR c, assuming a, b, and c are bool (true for odd count of true)
        std::cout << "a != b != c -> true (a XOR b XOR c)\n";

    // For non-bool operands, convert explicitly
    int i{ 1 };
    int j{ 0 };
    if (static_cast<bool>(i) != static_cast<bool>(j))
        std::cout << "static_cast<bool>(i) != static_cast<bool>(j) -> true\n";

    if (!!i != !!j) // double NOT converts any type to bool
        std::cout << "!!i != !!j -> true\n";
    // --- 原文示例片段结束 ---

    return 0;
}
