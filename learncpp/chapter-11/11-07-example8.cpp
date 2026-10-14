// 来源小节：11.7 Function template instantiation
// 示例说明：用 C 风格字符串字面量调用 addOne，T 推导为 const char*，x + 1 变成指针算术，
//           语法合法但语义无意义（这是语义错误，不是语法错误）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：ello, world!

#include <iostream>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    // "Hello, world!" 是 const char[14]，退化为 const char*；x + 1 指向第二个字符 'e'
    std::cout << addOne("Hello, world!") << '\n'; // 编译通过！输出 "ello, world!"

    return 0;
}
