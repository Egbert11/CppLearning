// ============================================================
// 来源小节：13.13 Class templates
// 文件说明：头文件，含头文件保护、Pair 类模板与 max 函数模板（原 Example 16）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：模板定义放在头文件中，可被多个 .cpp 包含。本节代码为按原文重建。
// ============================================================
#ifndef PAIR_H
#define PAIR_H

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

#endif
