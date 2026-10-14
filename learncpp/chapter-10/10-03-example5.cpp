// 来源小节：10.3 Numeric conversions
// 示例说明：平台相关的有损转换——把 long long 10000000000000001 转成 double 再转回，
//           double 的精度不足以区分该值与 10000000000000000，末位 1 被丢弃。
//           （对应原文示例 13）
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example5.cpp -o a
// 预期输出：10000000000000000
//
// 本节代码为按原文描述重建（原文即用 long long 字面量演示）。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << static_cast<long long>(static_cast<double>(10000000000000001LL)) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
