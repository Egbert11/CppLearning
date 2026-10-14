// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：从函数调用推导类型——add(5, 6) 的结果是 int，故 sum 推导为 int。
//           （对应原文示例 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example2.cpp -o a
// 预期输出：11
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    // --- 原文示例片段 ---
    auto sum{ add(5, 6) }; // add() returns int, so sum is deduced as int
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(sum), int>);

    std::cout << sum << '\n'; // 11

    return 0;
}
