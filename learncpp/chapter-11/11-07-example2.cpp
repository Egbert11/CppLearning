// 来源小节：11.7 Function template instantiation
// 示例说明：同一模板生成两个实例：max<int> 与 max<double>；同一实例第二次调用被复用
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：
// 2
// 4
// 2

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)

    return 0;
}
