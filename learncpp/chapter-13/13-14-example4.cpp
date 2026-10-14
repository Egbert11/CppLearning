// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：用户自定义聚合 Pair 的 CTAD —— C++17 下失败，C++20 下成功。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
//       注意：教学点是"Pair p2{1,2} 在 C++17 下编译失败"。本仓库统一用 -std=c++20 编译，
//       故在此可正常通过（C++20 会自动为聚合生成推导指引）。用 -std=c++17 编译则 p2 报错。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 4）---
// define our own Pair type
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

int main()
{
    Pair<int, int> p1{ 1, 2 }; // ok: we're explicitly specifying the template arguments
    Pair p2{ 1, 2 };           // compile error in C++17 (okay in C++20)

    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';

    return 0;
}

// 预期输出（C++20）：
// 1 2
// 1 2
