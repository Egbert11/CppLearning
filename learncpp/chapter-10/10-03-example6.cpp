// 来源小节：10.3 Numeric conversions
// 示例说明：越界赋值——把 int 30000 存入 char（char 范围通常是 -128..127），
//           数值按模回绕，再转回 int 得到 48。（对应原文示例 14）
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example6.cpp -o a
// 预期输出：48
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int i{ 30000 };
    char c = i; // chars have range -128 to 127
    // --- 原文示例片段结束 ---

    std::cout << static_cast<int>(c) << '\n'; // 48（30000 对 256 取模）

    return 0;
}
