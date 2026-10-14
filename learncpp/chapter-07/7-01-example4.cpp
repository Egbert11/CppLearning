// 来源小节：7.1 Compound statements (blocks)
// 示例说明：嵌套层级（nesting level）——同时在其中的块的最大数量。本程序有 4 个块，
//           嵌套层级为 3（含最外层块）。（对应原文 Example 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
//
// 预期输出（输入 4）：
//   Enter an integer: 4
//   4 is positive and even
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // block 1, nesting level 1
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value >  0)
    { // block 2, nesting level 2
        if ((value % 2) == 0)
        { // block 3, nesting level 3
            std::cout << value << " is positive and even\n";
        }
        else
        { // block 4, also nesting level 3
            std::cout << value << " is positive and odd\n";
        }
    }

    return 0;
}
