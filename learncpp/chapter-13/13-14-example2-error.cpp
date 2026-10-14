// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：一旦写了模板实参列表，CTAD 就不再推导剩余实参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 预期错误：error: too few template arguments for class template 'pair'
//           （一个或两个实参都未被推导）
// 备注：本节代码为按原文描述忠实重建。故意编译失败，用于演示"CTAD 只在没有实参列表时发生"，请勿修复。
// ============================================================
#include <iostream>
#include <utility> // for std::pair

int main()
{
    // --- 原文示例片段（原 Example 2）---
    std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
    std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

    return 0;
}
