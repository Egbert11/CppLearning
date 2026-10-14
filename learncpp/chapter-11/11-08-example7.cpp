// 来源小节：11.8 Function templates with multiple template types
// 示例说明：把返回类型改成 auto，让编译器从 return 语句推导出正确的公共类型 double
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：3.5

#include <iostream>

template <typename T, typename U>
auto max(T x, U y) // auto 返回类型会推导为公共类型 double
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // 输出 3.5

    return 0;
}
