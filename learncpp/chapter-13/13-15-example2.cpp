// ============================================================
// 来源小节：13.15 Alias templates
// 示例说明：别名模板 Coord<T> = Pair<T>；Coord<int> 显式实参，Coord p2 依赖 C++20 别名模板推导。
// 原文链接：https://www.learncpp.com/cpp-tutorial/alias-templates/
// 备注：本节代码为按原文描述忠实重建。需要 -std=c++20（Coord p2 用到 C++20 推导）。
// ============================================================
#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// --- 原文示例片段（原 Example 2）---
// Here's our alias template
// Alias templates must be defined in global scope
template <typename T>
using Coord = Pair<T>; // Coord is an alias for Pair<T>

// Our print function template needs to know that Coord's template parameter T is a type template parameter
template <typename T>
void print(const Coord<T>& c)
{
    std::cout << c.first << ' ' << c.second << '\n';
}

int main()
{
    Coord<int> p1 { 1, 2 }; // Pre-C++20: Must specify all type template arguments explicitly
    Coord p2 { 1, 2 };      // In C++20, alias template deduction will deduce Coord<int> here

    std::cout << p1.first << ' ' << p1.second << '\n';
    print(p2);

    return 0;
}

// 预期输出：
// 1 2
// 1 2
