// ============================================================
// 来源小节：13.13 Class templates
// 示例说明：用单个函数模板 max(T, T) 替代两个重载，调用时实例化对应特化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';        // instantiates and calls max<int>(int, int)
    std::cout << max<double>(1.5, 2.5) << '\n'; // instantiates and calls max<double>(double, double)

    return 0;
}

// 预期输出：
// 2
// 2.5
