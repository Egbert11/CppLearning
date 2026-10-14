// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：当源值是 constexpr 且能安全放进目标类型时，同样的转换不算收窄，
//           列表初始化与拷贝初始化都能通过。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

void foo(unsigned int)
{
}

int main()
{
    constexpr int s { 5 };                 // now constexpr
    [[maybe_unused]] unsigned int u { s }; // ok: s is constexpr and can be converted safely, not a narrowing conversion
    foo(s);                                // ok: s is constexpr and can be converted safely, not a narrowing conversion

    return 0;
}
