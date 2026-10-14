// 来源小节：5.8 Introduction to std::string_view
// 示例说明：std::string_view 不能隐式转换为 std::string；需要转换时有两种显式做法：
//           (a) 用 std::string_view 作初始化器构造 std::string；
//           (b) 用 static_cast<std::string>(sv)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 7）。
// 原示例中 `printString(sv);` 是【编译错误】（无隐式转换），为让本文件可通过编译，
// 该行以注释保留（见下方）。
// 预期输出：
//   Hello, world!
//   Hello, world!

#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view sv{ "Hello, world!" };

    // printString(sv);   // compile error: no implicit conversion from std::string_view to std::string  <-- 取消注释将无法编译

    std::string s{ sv };  // ok: we can explicitly construct a std::string from a std::string_view
    printString(s);

    printString(static_cast<std::string>(sv)); // ok: we can also static_cast

    return 0;
}
