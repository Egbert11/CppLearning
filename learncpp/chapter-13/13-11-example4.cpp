// ============================================================
// 来源小节：13.11 Struct miscellany
// 示例说明：struct 大小可能大于成员之和——编译器为对齐插入了填充字节。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-miscellany/
// 备注：本节代码为按原文描述忠实重建。具体字节数依平台/编译器而定。
// ============================================================
#include <iostream>

struct Foo
{
    short a {}; // 2 bytes
    int b {};   // 4 bytes
    double c {}; // 8 bytes
};

int main()
{
    // --- 原文示例片段（原 Example 4）---
    std::cout << "The size of short is " << sizeof(short) << " bytes\n";
    std::cout << "The size of int is " << sizeof(int) << " bytes\n";
    std::cout << "The size of double is " << sizeof(double) << " bytes\n";
    std::cout << "The size of Foo is " << sizeof(Foo) << " bytes\n";

    return 0;
}

// 预期输出（作者机器上，成员共 14 字节，Foo 报告 16 字节，即 a 后有 2 字节填充）：
// The size of short is 2 bytes
// The size of int is 4 bytes
// The size of double is 8 bytes
// The size of Foo is 16 bytes
