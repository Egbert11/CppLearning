// 来源小节：5.7 Introduction to std::string
// 示例说明：s 后缀的 std::string 字面量——"goo\n" 是 C 风格字面量，
//           而 "goo\n"s 是 std::string 字面量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 14）。
// 预期输出：
//   goo
//   goo

#include <iostream>
#include <string> // for std::string and std::string_literals

using namespace std::string_literals; // easy access to the s suffix

int main()
{
    std::cout << "goo\n";  // C-style string literal (the default)
    std::cout << "goo\n"s; // s suffix is a std::string literal

    return 0;
}
