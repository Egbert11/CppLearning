// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：为两参数 Pair 写推导指引，使其在 C++17 下也能使用 CTAD。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 5、6）---
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main()
{
    Pair<int, int> p1{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p2{ 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)

    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';

    return 0;
}

// 预期输出：
// 1 2
// 1 2
