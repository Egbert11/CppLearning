// 来源小节：11.9 Non-type template parameters（本节测验解答）
// 示例说明：写一个 constexpr 阶乘函数模板；用 static_assert(N >= 0) 保证 N 非负。
//           本文件只保留可通过的断言（去掉会失败编译的 factorial<-3>() 调用）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期输出：无（编译期断言通过即可）

#include <iostream>

template <int N>
constexpr int factorial()
{
    static_assert(N >= 0);

    int product { 1 };
    for (int i { 2 }; i <= N; ++i)
        product *= i;

    return product;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    return 0;
}
