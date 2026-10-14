// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：声明 C 风格字符串变量——固定长度、由初始化器推导长度、constexpr（原 Example 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：
//   str1: 8
//   str2: 7
//   str3: 6
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    char str1[8]{};                    // an array of 8 char, indices 0 through 7

    const char str2[]{ "string" };     // an array of 7 char, indices 0 through 6
    constexpr char str3[] { "hello" }; // an array of 6 const char, indices 0 through 5

    std::cout << "str1: " << std::size(str1) << '\n';
    std::cout << "str2: " << std::size(str2) << '\n';
    std::cout << "str3: " << std::size(str3) << '\n';

    return 0;
}
