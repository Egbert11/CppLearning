// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：按值返回的结果是右值。用 getHello() 的返回值初始化 const
//           std::string s 是安全的，该右值在本条完整表达式结束时销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 12）。
// ============================================================
#include <iostream>
#include <string>

std::string getHello()
{
    return std::string{ "Hello" }; // return a temporary by value
}

int main()
{
    const std::string s{ getHello() }; // okay: the temporary is destroyed at the end of this full expression

    std::cout << s << '\n';

    return 0;
}
