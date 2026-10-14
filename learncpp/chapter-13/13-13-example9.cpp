// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：鸭子类型的 print(T) —— 只要类型有 first/second 成员即可匹配，Pair 与 Point 皆可。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。Point 为配合示例，也定义了 first/second 成员。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 13）---
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

struct Point
{
    double first{};  // must have members named first and second for print() to match
    double second{};
};

template <typename T>
void print(T p) // type template parameter will match anything
{
    // note: this requires T to have members named first and second
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    Pair<double, int> p1{ 4.5, 6 };
    print(p1); // matches Pair<double, int>

    Point pt{ 3.4, 5.6 };
    print(pt); // matches Point

    return 0;
}

// 预期输出：
// [4.5, 6]
// [3.4, 5.6]
