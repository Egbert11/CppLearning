// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：直接列表初始化临时量只允许单词类型名，`unsigned int { c }` 是多词类型名，
//           因此编译失败。（对应原文示例 14）
//           编译器报错形如：error: expected primary-expression before 'unsigned'
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example9-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    unsigned char c{ 'a' };

    // --- 原文示例片段 ---
    std::cout << unsigned int{ c } << '\n'; // compile error
    // --- 原文示例片段结束 ---

    return 0;
}
