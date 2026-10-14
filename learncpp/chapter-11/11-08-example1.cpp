// 来源小节：11.8 Function templates with multiple template types
// 示例说明：单类型参数模板 max<T>，用类型匹配的实参调用，可以正常编译
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：
// 2
// 2.5

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(1, 2) << '\n';       // instantiates max<int>(int, int)
    std::cout << max(1.5, 2.5) << '\n';   // instantiates max<double>(double, double)

    return 0;
}
