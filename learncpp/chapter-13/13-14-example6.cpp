// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：单模板类型的 Pair 及其推导指引 Pair(T, T) -> Pair<T>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 7）---
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
template <typename T>
Pair(T, T) -> Pair<T>;

int main()
{
    Pair<int> p1{ 1, 2 }; // explicitly specify class template Pair<int> (C++11 onward)
    Pair p2{ 1, 2 };      // CTAD used to deduce Pair<int> from the initializers (C++17)

    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';

    return 0;
}

// 预期输出：
// 1 2
// 1 2
