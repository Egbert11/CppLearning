// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：类型模板参数可带默认值，在未显式指定且无法推导时使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 8）---
template <typename T=int, typename U=int> // default T and U to type int
struct Pair
{
    T first{};
    U second{};
};

template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main()
{
    Pair<int, int> p1{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p2{ 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)

    Pair p3;                   // uses default Pair<int, int>

    std::cout << p1.first << p1.second << '\n';
    std::cout << p2.first << p2.second << '\n';
    std::cout << p3.first << p3.second << '\n';

    return 0;
}

// 预期输出：
// 12
// 12
// 00
