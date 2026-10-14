// 来源小节：11.7 Function template instantiation
// 示例说明（进阶）：用函数模板特化 + = delete 禁止 const char* 版本的 addOne，
//                   于是 addOne("Hello, world!") 变成编译错误。预期编译失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期错误：use of deleted function 'const char* addOne(const char*)'

#include <iostream>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to delete the const char* instantiation
template <>
const char* addOne(const char* x) = delete;

int main()
{
    std::cout << addOne("Hello, world!") << '\n'; // compile error: use of deleted function

    return 0;
}
