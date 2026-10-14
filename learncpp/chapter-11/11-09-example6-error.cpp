// 来源小节：11.9 Non-type template parameters
// 示例说明：对 int 与 char 两种非类型参数重载 print()；模板匹配不按转换排优先级，
//           因此 print<5>() 与 print<'c'>() 都是歧义匹配。预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期错误：call of overloaded 'print<5>()' is ambiguous（char 与 int 版本都可匹配）

#include <iostream>

template <int N> // int non-type template parameter
void print()
{
    std::cout << N << '\n';
}

template <char N> // char non-type template parameter
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // ambiguous match with int N = 5 and char N = 5
    print<'c'>(); // ambiguous match with int N = 99 and char N = 'c'

    return 0;
}
