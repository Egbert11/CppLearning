// 来源小节：11.8 Function templates with multiple template types
// 示例说明：方案 B —— 显式模板实参 max<double> 禁用推导，随后 int 被隐式转换为 double
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
    std::cout << max<double>(2, 3.5) << '\n'; // 显式指定 T=double，2 被转换为 2.0

    return 0;
}
