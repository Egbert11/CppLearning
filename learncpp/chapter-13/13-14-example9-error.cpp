// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：CTAD 不能用于函数参数（CTAD 是实参推导，不是形参推导）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 预期错误：error: class template argument deduction is only available with ... / CTAD not allowed here
//           （void print(std::pair p) 处）
// 备注：本节代码为按原文描述忠实重建。故意编译失败，请勿修复；修正版见 13-14-example10.cpp。
// ============================================================
#include <iostream>
#include <utility>

// --- 原文示例片段（原 Example 10）---
void print(std::pair p) // compile error, CTAD can't be used here
{
    std::cout << p.first << ' ' << p.second << '\n';
}

int main()
{
    std::pair p { 1, 2 }; // p deduced to std::pair<int, int>
    print(p);

    return 0;
}
