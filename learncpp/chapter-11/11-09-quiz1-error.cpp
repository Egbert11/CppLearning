// 来源小节：11.9 Non-type template parameters（本节测验解答的失败版本）
// 示例说明：与 quiz1 相同，但额外调用 factorial<-3>()，static_assert(N >= 0) 触发编译失败。
//           这正是题目要求"必须在 factorial<-3>() 处编译失败"的部分。预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期错误：static assertion failed: N >= 0

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

    factorial<-3>(); // should fail to compile

    return 0;
}
