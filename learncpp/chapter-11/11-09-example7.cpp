// 来源小节：11.9 Non-type template parameters
// 示例说明：C++17 起，template <auto N> 让编译器从实参推导非类型参数的类型
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 需要：C++17（auto 非类型模板参数）
// 预期输出：
// 5
// c

#include <iostream>

template <auto N> // deduce non-type template parameter from template argument
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // N deduced as int `5`
    print<'c'>(); // N deduced as char `c`

    return 0;
}
