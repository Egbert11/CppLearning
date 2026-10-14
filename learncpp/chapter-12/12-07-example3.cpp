// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：取地址运算符 & 返回操作数的内存地址。地址通常以十六进制
//           打印，常省略 0x 前缀。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
//       地址的具体数值因运行而异，下面注释只是示例。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出（地址随运行变化）：
// 5
// 0027FEA0
