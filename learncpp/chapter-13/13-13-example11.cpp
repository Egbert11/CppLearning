// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：用标准库 std::pair 加 print(std::pair<T,U>) 函数模板，取代手写的 Pair。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <utility> // for std::pair

// --- 原文示例片段（原 Example 15）---
template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    std::pair<int, double> p1{ 1, 2.3 };
    print(p1);

    return 0;
}

// 预期输出：
// [1, 2.3]
