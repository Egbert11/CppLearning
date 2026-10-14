// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 2）
// 示例说明：字符串验证——isValidName 只允许字母或空格（用 std::ranges::all_of），
//           并循环用 std::getline 直到姓名合法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/
// 预期：需要交互输入；输入含数字/符号的姓名会提示重输。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <algorithm> // std::all_of
#include <cctype> // std::isalpha, std::isspace
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

bool isValidName(std::string_view name)
{
  return std::ranges::all_of(name, [](char ch) {
    return std::isalpha(ch) || std::isspace(ch);
  });

  // Before C++20, without ranges
  // return std::all_of(name.begin(), name.end(), [](char ch) {
  //    return std::isalpha(ch) || std::isspace(ch);
  // });
}

int main()
{
  std::string name{};

  do
  {
    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // get the entire line, including spaces
  } while (!isValidName(name));

  std::cout << "Hello " << name << "!\n";
}
