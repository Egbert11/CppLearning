// 来源小节：11.9 Non-type template parameters
// 示例说明：字符实参 'c' 隐式转换为 int 非类型参数（整型提升/转换），值为 99
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期输出：
// 5
// 99

#include <iostream>

template <int N> // int non-type template parameter
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // no conversion necessary
    print<'c'>(); // 'c' converted to type int, prints 99

    return 0;
}
