// 来源小节：11.7 Function template instantiation
// 示例说明：addOne 分别以 int、double 实例化，各生成一个函数
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：
// 2
// 3.3

#include <iostream>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::cout << addOne(1) << '\n';   // instantiates addOne<int>
    std::cout << addOne(2.3) << '\n'; // instantiates addOne<double>

    return 0;
}
