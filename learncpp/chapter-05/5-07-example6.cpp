// 来源小节：5.7 Introduction to std::string
// 示例说明：获取字符串长度。length() 返回无符号值（size_t），
//           C++20 的 std::ssize() 返回有符号值；存进 int 时都应显式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 12–13）。
// 预期输出：
//   Alex has 4 characters
//   Alex has 4 characters

#include <iostream>
#include <iterator> // for std::ssize (C++20)
#include <string>

int main()
{
    std::string name { "Alex" };

    std::cout << name << " has " << name.length() << " characters\n"; // members function length()
    std::cout << name << " has " << std::ssize(name) << " characters\n"; // C++20 std::ssize()

    return 0;
}
