// 来源小节：11.7 Function template instantiation
// 示例说明：用 std::string 调用 addOne，生成的 std::string addOne<std::string>(std::string) 中
//           x + 1 非法（std::string 没有与 int 的 operator+），预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期错误：no match for 'operator+' (std::string 与 int)

#include <iostream>
#include <string>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::string hello{ "Hello, world!" };
    std::cout << addOne(hello) << '\n'; // compile error: x + 1 对 std::string 非法

    return 0;
}
