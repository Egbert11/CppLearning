// 来源小节：4.11 Chars
// 示例说明：用 std::cin.get(ch) 修复空白提取——get() 不跳过前导空白。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 假设输入 "a b"，预期输出：
//   You entered: a
//   You entered:  （一个空格）

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin.get(ch); // ch = 'a', " b" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin.get() reads the next character, which is the space
    std::cin.get(ch); // ch = ' ' (space)
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
