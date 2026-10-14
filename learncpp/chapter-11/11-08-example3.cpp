// 来源小节：11.8 Function templates with multiple template types
// 示例说明：方案 A —— 调用方用 static_cast 把 int 转成 double，使两者匹配 max(double, double)
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：3.5

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // instantiates max<double>(double, double)

    return 0;
}
