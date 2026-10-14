// ============================================================
// 来源小节：13.15 Alias templates
// 示例说明：为完全指定的类模板 Pair<int> 起一个普通类型别名 Point。
// 原文链接：https://www.learncpp.com/cpp-tutorial/alias-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
void print(const Pair<T>& p)
{
    std::cout << p.first << ' ' << p.second << '\n';
}

int main()
{
    // --- 原文示例片段（原 Example 1）---
    using Point = Pair<int>; // create normal type alias to a fully-specified class template
    Point p { 1, 2 };        // compiler replaces this with Pair<int> p

    print(p);

    return 0;
}

// 预期输出：
// 1 2
