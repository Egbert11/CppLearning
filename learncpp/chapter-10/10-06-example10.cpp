// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：用单词类型别名 uint（= unsigned int）绕过示例 9 的限制，列表初始化
//           临时量即可通过。（对应原文示例 15）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example10.cpp -o a
// 预期输出：97
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    unsigned char c{ 'a' };

    // --- 原文示例片段 ---
    using uint = unsigned int;
    std::cout << uint{ c } << '\n'; // 97
    // --- 原文示例片段结束 ---

    return 0;
}
