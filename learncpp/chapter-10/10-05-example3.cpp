// 来源小节：10.5 Arithmetic conversions
// 示例说明：无符号算术的意外——5u - 10 中，5u 是无符号，10 被转成无符号，
//           结果为无符号的大数 4294967291，而不是 -5。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-05-example3.cpp -o a
// 注：typeid().name() 输出实现相关；原文输出 "unsigned int 4294967291"，
//     GCC 下类型名显示为 'j'（unsigned int 的平台化简写）。数值一致。
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <typeinfo>

int main()
{
    // --- 原文示例片段 ---
    // 5u means treat 5 as an unsigned integer
    std::cout << typeid(5u - 10).name() << ' ' << 5u - 10 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
