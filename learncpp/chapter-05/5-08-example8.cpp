// 来源小节：5.8 Introduction to std::string_view
// 示例说明：与 std::string 不同，std::string_view 支持 constexpr，
//           因此 constexpr std::string_view 可用作字符串符号常量，值在编译期即可替换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 10）。
// 预期输出：
//   Hello, world!

#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view s{ "Hello, world!" }; // constexpr std::string_view is fine
    std::cout << s << '\n';

    return 0;
}
