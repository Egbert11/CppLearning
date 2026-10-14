// 来源小节：5.8 Introduction to std::string_view
// 示例说明：给 std::string_view 赋新值只是“重新绑定”它查看的对象，
//           先前被查看的 std::string 内容不受影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 8）。
// 预期输出：
//   Alex
//   John
//   Alex

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n';      // prints Alex

    sv = "John";                  // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n';      // prints John
    std::cout << name << '\n';    // prints Alex

    return 0;
}
