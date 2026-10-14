// 来源小节：5.8 Introduction to std::string_view
// 示例说明：std::string_view 可用 C 风格字面量、std::string、另一个 std::string_view 初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 5）。
// 预期输出：
//   Hello, world!
//   Hello, world!
//   Hello, world!

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view s1 { "Hello, world!" }; // initialize with C-style string literal
    std::cout << s1 << '\n';

    std::string s{ "Hello, world!" };
    std::string_view s2 { s };  // initialize with std::string
    std::cout << s2 << '\n';

    std::string_view s3 { s2 }; // initialize with std::string_view
    std::cout << s3 << '\n';

    return 0;
}
