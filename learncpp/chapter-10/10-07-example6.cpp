// 来源小节：10.7 Typedefs and type aliases
// 示例说明：定宽整数类型（int8_t 等）其实是基础类型的别名。std::int8_t 通常是
//           signed char，所以打印 97 会显示成字符 'a'，而不是数字 97。
//           （对应原文示例 10、11；示例 10 是条件编译选择别名的平台前后缀方案，
//           此处以上下文中的 <cstdint> 定宽别名演示，语义一致。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example6.cpp -o a
// 预期输出：a
//
// 本节代码为按原文描述重建。

#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::int8_t x{ 97 }; // std::int8_t 通常是 signed char
    std::cout << x << '\n'; // 打印 'a' 而非 97
    // --- 原文示例片段结束 ---

    return 0;
}
