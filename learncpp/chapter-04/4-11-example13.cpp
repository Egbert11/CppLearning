// 来源小节：4.11 Chars
// 示例说明：引号、反斜杠与十六进制转义序列。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 预期输出：
//   "This is quoted text"
//   This string contains a single backslash \  (行末即一个反斜杠)
//   6F in hex is char 'o'

#include <iostream>

int main()
{
    std::cout << "\"This is quoted text\"\n";
    std::cout << "This string contains a single backslash \\\n";
    std::cout << "6F in hex is char '\x6F'\n";

    return 0;
}
