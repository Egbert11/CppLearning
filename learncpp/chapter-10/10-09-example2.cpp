// 来源小节：10.9 Type deduction for functions
// 示例说明：同一函数改用 auto 返回类型，编译器从 return x + y（int）推导为 int。
//           （对应原文示例 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example2.cpp -o a
// 预期输出：11
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

// --- 原文示例片段 ---
auto add(int x, int y)
{
    return x + y;
}
// --- 原文示例片段结束 ---

int main()
{
    static_assert(std::is_same_v<decltype(add(5, 6)), int>);
    std::cout << add(5, 6) << '\n'; // 11
    return 0;
}
