// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：解引用运算符 *（又称间接寻址运算符）返回给定内存地址处的
//           值，且该值是一个左值。&x 与 *(&x) 互为逆运算。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
//       地址的具体数值因运行而异，下面注释只是示例。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    std::cout << x << '\n';     // print the value of variable x
    std::cout << &x << '\n';    // print the memory address of variable x
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出（地址随运行变化）：
// 5
// 0027FEA0
// 5
