// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：与 Example 12 行为相同，只是右值先经一个 const 引用形参传入、
//           再按 const 引用返回。因为右值要到本条完整表达式结束才销毁，
//           返回的引用在此期间仍然有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 13）。
// ============================================================
#include <iostream>
#include <string>

std::string getHello()
{
    return std::string{ "Hello" };
}

const std::string& foo(const std::string& s)
{
    return s;
}

int main()
{
    const std::string s{ foo(getHello()) }; // okay: the rvalue lives until the end of the full expression

    std::cout << s << '\n';

    return 0;
}
