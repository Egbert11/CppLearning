// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：浮点 -> 整型没有 constexpr 例外条款：即使 5.0 是 constexpr 且落在 int
//           范围内，这一转换仍被视为窄化，故编译失败。
//           编译器报错形如：error: narrowing conversion of '5.0e+0' from 'double' to 'int'
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example6-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    // --- 原文示例片段 ---
    int n{ 5.0 }; // compile error: narrowing conversion
    // --- 原文示例片段结束 ---

    return 0;
}
