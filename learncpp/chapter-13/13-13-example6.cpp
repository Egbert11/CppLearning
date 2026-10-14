// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：Pair 类模板配合 max 函数模板（参数为 Pair<T>）；显式调用与推导调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 7、8、9）---
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second) ? p.second : p.first;
}

int main()
{
    Pair<int> p1{ 5, 6 };
    std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>

    Pair<double> p2{ 1.2, 3.4 };
    std::cout << max(p2) << " is larger\n"; // deduced call to max<double> (preferred)

    return 0;
}

// 预期输出：
// 6 is larger
// 3.4 is larger
