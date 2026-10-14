// 来源小节：5.9 std::string_view (part 2)
// 示例说明：安全的返回——返回 C 风格字符串字面量的视图。字面量贯穿整个程序，
//           因此返回的视图始终有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 9）。
// 预期输出：
//   true false

#include <iostream>
#include <string_view>

std::string_view getBoolName(bool b)
{
    if (b)
        return "true"; // return a std::string_view viewing "true"

    return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed here, so the returned view is valid

int main()
{
    std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // ok: prints "true false"

    return 0;
}
