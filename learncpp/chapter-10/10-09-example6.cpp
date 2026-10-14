// 来源小节：10.9 Type deduction for functions
// 示例说明：尾置返回语法——auto 写在参数前，真正的返回类型写在 -> 之后；
//           这里的 auto 不做推导，只是语法形式。（对应原文示例 6）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example6.cpp -o a
// 预期输出：11
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
auto add(int x, int y) -> int
{
    return (x + y);
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << add(5, 6) << '\n'; // 11
    return 0;
}
