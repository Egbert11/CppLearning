// ============================================================
// 来源小节：13.15 Alias templates
// 示例说明：把别名模板用作函数形参却不写模板实参 —— 预期编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/alias-templates/
// 预期错误：error: use of alias template 'Coord' without template arguments
//           / missing template arguments before '&'
// 备注：本节代码为按原文描述忠实重建。故意编译失败，请勿修复；正确写法见 13-15-example2.cpp。
// ============================================================
#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
using Coord = Pair<T>;

// --- 原文示例片段（原 Example 2 的"不工作的写法"）---
// void print(const Coord& c) // won't work, missing template arguments
// {
//     std::cout << c.first << ' ' << c.second << '\n';
// }

void print(const Coord& c) // compile error: Coord requires template arguments here
{
    std::cout << c.first << ' ' << c.second << '\n';
}

int main()
{
    Coord<int> p { 1, 2 };
    print(p);

    return 0;
}
