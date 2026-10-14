// 来源小节：4.11 Chars
// 示例说明：空白提取问题——假设输入 "a b"，两次 >> 提取得到 'a' 再得到 'b'（空格被跳过）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 预期输出：
//   You entered: a
//   You entered: b

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin >> ch; // ch = 'a', " b" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin discards the leading whitespace and reads the next character
    std::cin >> ch; // ch = 'b', discards the leading space
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
