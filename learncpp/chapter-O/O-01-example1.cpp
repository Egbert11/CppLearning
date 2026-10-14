// 来源小节：O.1 Bit flags and bit manipulation via std::bitset
// 示例说明：演示一个普通变量保存单个值（与逐位标志的做法形成对照）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int foo { 5 }; // assign foo the value 5 (probably uses 32 bits of storage)
    std::cout << foo << '\n'; // print the value 5
    // --- 原文示例片段结束 ---

    return 0;
}
