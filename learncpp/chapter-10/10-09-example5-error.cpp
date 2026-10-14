// 来源小节：10.9 Type deduction for functions
// 示例说明：返回 auto 的函数只有在被完整定义之后才能调用；若此处仅有前向声明，
//           编译器信息不足，无法推导返回类型，编译失败。
//           编译器报错形如（MSVC）：
//             error C3779: 'foo': a function that returns 'auto' cannot be used
//             before it is defined.
//           （GCC 形如：error: use of 'auto foo()' before deduction of 'auto'）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example5-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
auto foo(); // 前向声明：信息不足以推导返回类型

int main()
{
    std::cout << foo() << '\n'; // the compiler has only seen a forward declaration at this point
    return 0;
}

auto foo() // 定义放在了调用之后
{
    return 5;
}
// --- 原文示例片段结束 ---
