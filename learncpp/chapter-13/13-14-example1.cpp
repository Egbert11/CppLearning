// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：std::pair 显式指定模板实参与 CTAD 自动推导两种写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <utility> // for std::pair

int main()
{
    // --- 原文示例片段（原 Example 1）---
    std::pair<int, int> p1{ 1, 2 }; // explicitly specify class template std::pair<int, int> (C++11 onward)
    std::pair p2{ 1, 2 };           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)

    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';

    return 0;
}

// 预期输出：
// 1 2
// 1 2
