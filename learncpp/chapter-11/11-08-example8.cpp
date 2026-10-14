// 来源小节：11.8 Function templates with multiple template types
// 示例说明（进阶）：需要可前置声明的场景，用尾置返回类型 std::common_type_t<T, U> 表达公共类型
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：3.5

#include <iostream>
#include <type_traits> // for std::common_type_t

// 前置声明：尾置返回类型写明公共类型，满足可前置声明的要求
template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>;

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // 输出 3.5

    return 0;
}
