// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：用 static_cast<int> 把 char 'a' 打印成它的整数值 97，而不是字符 a。
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example3.cpp -o a
// 预期输出：97
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    char c{ 'a' };
    std::cout << static_cast<int>(c) << '\n'; // prints 97 rather than a
    // --- 原文示例片段结束 ---

    return 0;
}
