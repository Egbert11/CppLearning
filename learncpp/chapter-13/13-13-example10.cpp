// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：把模板参数命名为 Pair 会遮蔽类类型 Pair，导致 print() 静默匹配任意类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。此文件可编译且运行，但属于应避免的坏做法。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 14）---
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

struct Point
{
    double first{};
    double second{};
};

template <typename Pair> // 'Pair' shadows the class type Pair
void print(Pair p)       // this now matches any type, not just our Pair class template
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    Pair<int, int> p1{ 1, 2 };
    print(p1);

    Point pt{ 3.4, 5.6 };
    print(pt); // note: this also compiles because the template parameter name shadows Pair

    return 0;
}

// 预期输出：
// [1, 2]
// [3.4, 5.6]
