// 来源小节：5.9 std::string_view (part 2)
// 示例说明：对比按值传 std::string（会拷贝）与传 std::string_view（不拷贝）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 1–2）。
// 预期输出：
//   Hello, world!
//   Hello, world!
//   Hello, world!
//   Hello, world!
//   Hello, world!

#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str) // str is a copy of the std::string passed in
{
    std::cout << str << '\n';
}

void printSV(std::string_view str) // str is a view into the passed-in string (no copy)
{
    std::cout << str << '\n';
}

int main()
{
    printString("Hello, world!");
    printSV("Hello, world!");

    std::string s{ "Hello, world!" };
    printString(s);
    printSV(s);

    std::string_view sv{ s };
    printSV(sv);

    return 0;
}
