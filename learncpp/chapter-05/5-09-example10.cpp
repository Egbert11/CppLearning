// 来源小节：5.9 std::string_view (part 2)
// 示例说明：remove_prefix() 从视图左端裁掉字符，remove_suffix() 从右端裁掉；
//           两者都不改动被查看的底层字符串，且只有重新赋值才能复位视图。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 11）。
// 预期输出：
//   Peach
//   each
//   ea
//   Peach

#include <iostream>
#include <string_view>

int main()
{
    std::string_view str{ "Peach" };

    std::cout << str << '\n';

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);

    std::cout << str << '\n';

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);

    std::cout << str << '\n';

    str = "Peach"; // reset the view

    std::cout << str << '\n';

    return 0;
}
