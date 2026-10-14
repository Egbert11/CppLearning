// 来源小节：5.9 std::string_view (part 2)
// 示例说明：修改 std::string 使视图失效后，把视图重新赋值为 s，即可让它重新有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 7）。
// 预期输出：
//   Hello, world!
//   Hello, universe!

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    std::cout << sv << '\n'; // prints "Hello, world!"

    s = "Hello, universe!";  // modifies s (invalidates sv)
    sv = s;                  // re-validate the view

    std::cout << sv << '\n'; // prints "Hello, universe!"

    return 0;
}
