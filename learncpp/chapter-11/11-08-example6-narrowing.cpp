// 来源小节：11.8 Function templates with multiple template types
// 示例说明：方案 C 的两个模板参数，但返回类型写成了 T：条件运算符得到公共类型 double(3.5)，
//           再窄化回返回类型 int(3)。这是窄化 bug。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：3   （3.5 被窄化为 int）

#include <iostream>

// x can resolve to type T, and y can resolve to type U
template <typename T, typename U>
T max(T x, U y) // return type T 会窄化结果
{
    return (x < y) ? y : x; // 这里返回了 double 3.5，但被窄化为 int 3
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // 输出 3，不是 3.5

    return 0;
}
