// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：把 Pair 改写为类模板 template <typename T> struct Pair，并实例化 int/double。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。Pair<double> 第二次使用会复用已生成的定义。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 5）---
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

int main()
{
    Pair<int> p1{ 5, 6 };        // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2{ 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3{ 7.8, 9.0 }; // object p3 uses the previously instantiated Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';

    return 0;
}

// 预期输出：
// 5 6
// 1.2 3.4
// 7.8 9
