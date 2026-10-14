// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：（进阶读者）toASCIILowerCase 辅助函数：把 std::string_view 逐字符
//           通过 std::tolower 转成小写后，追加到返回的 std::string 中，从而让
//           前面的大小写敏感匹配变成大小写不敏感。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。只做 1:1 字符映射，不支持带重音的字符。
// ============================================================
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <iostream>
#include <iterator>  // for std::back_inserter
#include <string>
#include <string_view>

// This function returns a std::string that is the lower-case version of the std::string_view passed in.
// Only 1:1 character mapping can be performed by this function
std::string toASCIILowerCase(std::string_view sv)
{
    std::string lower{};
    std::transform(sv.begin(), sv.end(), std::back_inserter(lower),
        [](char c)
        {
            return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        });
    return lower;
}

int main()
{
    std::cout << toASCIILowerCase("HeLLo WorLD") << '\n';
    return 0;
}

// 预期输出：
// hello world
