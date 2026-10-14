// 来源小节：5.9 std::string_view (part 2)
// 示例说明：安全的返回——返回两个 std::string_view 形参中字典序较小的一个。
//           只要底层实参活得比这次调用长，返回的视图就有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 10）。
// 预期输出：
//   Hello

#include <iostream>
#include <string_view>

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
    if (s1 < s2)
        return s1;
    return s2;
}

int main()
{
    std::string_view a { "Hello" };
    std::string_view b { "World" };

    std::cout << firstAlphabetical(a, b) << '\n'; // prints "Hello"

    return 0;
}
