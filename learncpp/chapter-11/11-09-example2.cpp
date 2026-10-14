// 来源小节：11.9 Non-type template parameters
// 示例说明：带 int 非类型模板参数的函数模板 print()，调用 print<5>() 使 N 为 5
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期输出：5

#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print()
{
    std::cout << N << '\n'; // use value of N here
}

int main()
{
    print<5>(); // 5 is our non-type template argument

    return 0;
}
