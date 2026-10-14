// 来源小节：11.7 Function template instantiation
// 示例说明：模板混合类型模板参数 T 与非模板参数 double；T 精确推导，double 形参接受转换
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：5 5 5 5 5（每次调用都返回 5）

#include <iostream>

// T is a type template parameter
// double is a non-template parameter
template <typename T>
int someFcn(T, double)
{
    return 5;
}

int main()
{
    std::cout << someFcn(1, 3.4) << '\n';    // T = int,    double 参数精确匹配
    std::cout << someFcn(1, 3.4f) << '\n';   // T = int,    float 提升为 double
    std::cout << someFcn(1.2, 3.4) << '\n';  // T = double
    std::cout << someFcn(1.2f, 3.4) << '\n'; // T = float
    std::cout << someFcn('a', 3.4) << '\n';  // T = char

    return 0;
}
