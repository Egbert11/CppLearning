// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：两参数 Pair<T, U> 加 print(Pair<T, U>) 函数模板，匹配多种类型组合。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 11、12）---
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

template <typename T, typename U>
void print(Pair<T, U> p) // our print() function is constrained to objects of type Pair<T, U>
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    Pair<int, double> p1{ 1, 2.3 };
    Pair<double, int> p2{ 4.5, 6 };
    Pair<int, int> p3{ 7, 8 };

    print(p1);
    print(p2);
    print(p3);

    return 0;
}

// 预期输出：
// [1, 2.3]
// [4.5, 6]
// [7, 8]
