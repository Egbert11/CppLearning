// 来源小节：11.8 Function templates with multiple template types
// 示例说明：C++20 缩写函数模板——形参类型写 auto 即等价于两个独立的类型模板参数
//           等价于 template <typename T, typename U> auto max(T x, U y)
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 需要：C++20
// 预期输出：3.5

#include <iostream>

auto max(auto x, auto y) // abbreviated function template
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // 输出 3.5

    return 0;
}
