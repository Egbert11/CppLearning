// 来源小节：5.8 Introduction to std::string_view
// 示例说明：一个 std::string_view 形参可以接受三种实参——C 风格字面量、std::string、
//           std::string_view，因为前两者都能隐式转换为 std::string_view。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 6）。
// 预期输出：
//   Hello, world!
//   Hello, world!
//   Hello, world!

#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    printSV(s2); // call with std::string

    std::string_view s3 { s2 };
    printSV(s3); // call with std::string_view

    return 0;
}
