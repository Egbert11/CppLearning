// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：字符串字面量推导出 const char*，而不是 std::string。
//           （对应原文示例 9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example7.cpp -o a
// 预期输出：Hello, world
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    // --- 原文示例片段 ---
    auto s{ "Hello, world" }; // 推导为 const char*，而不是 std::string
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(s), const char*>);

    std::cout << s << '\n';

    return 0;
}
