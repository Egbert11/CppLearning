// 来源小节：11.8 Function templates with multiple template types
// 示例说明：重载的函数模板——同名的 add 分别有 1、2、3 个模板参数；
//           add(1.2, 3.4) 因部分排序优先选择更专用的 add<T>(T, T)
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：
// 4.6
// 12.6
// 27

#include <iostream>

template <typename T>
auto add(T x, T y)
{
    return x + y;
}

template <typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}

template <typename T, typename U, typename V>
auto add(T x, U y, V z)
{
    return x + y + z;
}

int main()
{
    std::cout << add(1.2, 3.4) << '\n';   // add<double>(double, double)     -> 4.6
    std::cout << add(5.6, 7) << '\n';     // add<double, int>                 -> 12.6
    std::cout << add(8, 9, 10) << '\n';   // add<int, int, int>               -> 27

    return 0;
}
