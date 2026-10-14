// 来源小节：5.8 Introduction to std::string_view
// 示例说明：三种字面量形态——无后缀是 C 风格字面量，s 后缀是 std::string 字面量，
//           sv 后缀是 std::string_view 字面量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 9）。
// 预期输出：
//   foo
//   goo
//   moo

#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

using namespace std::string_literals;      // for the s suffix
using namespace std::string_view_literals; // for the sv suffix

int main()
{
    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    return 0;
}
