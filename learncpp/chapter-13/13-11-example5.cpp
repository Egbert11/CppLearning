// ============================================================
// 来源小节：13.11 Struct miscellany
// 示例说明：成员相同但顺序不同，struct 大小因填充而不同（Foo1 比 Foo2 大 50%）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-miscellany/
// 备注：本节代码为按原文描述忠实重建。具体字节数依平台/编译器而定。
// ============================================================
#include <iostream>

struct Foo1
{
    short a{}; // 2 bytes
    int b{};   // 4 bytes (padding after a)
    short c{}; // 2 bytes (padding after c)
};

struct Foo2
{
    int b{};   // 4 bytes
    short a{}; // 2 bytes
    short c{}; // 2 bytes
};

int main()
{
    // --- 原文示例片段（原 Example 5）---
    std::cout << sizeof(Foo1) << '\n';
    std::cout << sizeof(Foo2) << '\n';

    return 0;
}

// 预期输出：
// 12
// 8
