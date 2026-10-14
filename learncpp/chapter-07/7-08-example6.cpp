// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：把 gravity 放进 constants 命名空间，用限定名 constants::gravity 访问——
//           降低命名冲突风险，也让"它是全局的"这一点更清晰。（对应原文 Example 6）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 预期输出：9.8
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

namespace constants
{
    constexpr double gravity { 9.8 }; // constexpr: internal linkage by default
}

int main()
{
    std::cout << constants::gravity << '\n';
    return 0;
}
