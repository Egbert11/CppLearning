// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：修正上一例 —— 用函数模板代替在函数参数中使用 CTAD。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <utility>

// --- 原文示例片段（原 Example 11）---
template <typename T, typename U>
void print(std::pair<T, U> p) // function template: deduce the parameters ourselves
{
    std::cout << p.first << ' ' << p.second << '\n';
}

int main()
{
    std::pair p { 1, 2 }; // p deduced to std::pair<int, int>
    print(p);

    return 0;
}

// 预期输出：
// 1 2
