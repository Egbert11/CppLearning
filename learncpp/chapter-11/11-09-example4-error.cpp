// 来源小节：11.9 Non-type template parameters
// 示例说明：用 template <double D> 非类型参数把断言搬到编译期；
//           getSqrt<-5.0>() 触发 static_assert 编译失败。预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 需要：C++20（浮点非类型模板参数）
// 预期错误：static assertion failed: getSqrt(): D must be non-negative

#include <cmath> // for std::sqrt
#include <iostream>

template <double D> // requires C++20 for floating point non-type parameters
double getSqrt()
{
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    if constexpr (D >= 0) // ignore the constexpr here for this example
        return std::sqrt(D); // strangely, std::sqrt isn't a constexpr function (until C++26)

    return 0.0;
}

int main()
{
    std::cout << getSqrt<5.0>() << '\n';
    std::cout << getSqrt<-5.0>() << '\n'; // compile error: static_assert 失败

    return 0;
}
