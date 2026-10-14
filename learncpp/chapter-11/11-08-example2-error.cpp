// 来源小节：11.8 Function templates with multiple template types
// 示例说明：同一个单类型参数模板用 int 与 double 混用调用 max(2, 3.5)，
//           T 无法推导出统一类型，模板参数 T 有歧义。预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期错误：template parameter 'T' is ambiguous / no matching function for call to 'max(int, double)'

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // compile error: 无法为 2 (int) 与 3.5 (double) 推导出同一个 T

    return 0;
}
