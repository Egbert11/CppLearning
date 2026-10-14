// 来源小节：11.7 Function template instantiation
// 示例说明：最基本的 max<T> 函数模板，以及触发隐式实例化的调用 max<int>(1, 2)
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：2

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}
