// 来源小节：5.8 Introduction to std::string_view
// 示例说明：改用 std::string_view 后输出与按值传 std::string 相同，但不再发生文本拷贝。
//           形参 str 是对传入字符串的只读访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 4）。
// 预期输出：
//   Hello, world!

#include <iostream>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view: no copy is made
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // view of the C-style string literal (no copy)
    printSV(s);

    return 0;
}
