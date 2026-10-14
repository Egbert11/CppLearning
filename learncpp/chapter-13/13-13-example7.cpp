// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：Foo 模板混用模板成员 T first 与固定普通成员 int second。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 10）---
template <typename T>
struct Foo
{
    T first{};  // the type of first will be whatever was passed in
    int second{}; // the type of second is always int
};

int main()
{
    Foo<int> f1{ 5, 6 };
    std::cout << f1.first << ' ' << f1.second << '\n';

    Foo<double> f2{ 1.2, 3 };
    std::cout << f2.first << ' ' << f2.second << '\n';

    return 0;
}

// 预期输出：
// 5 6
// 1.2 3
