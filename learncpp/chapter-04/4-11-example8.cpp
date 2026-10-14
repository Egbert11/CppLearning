// 来源小节：4.11 Chars
// 示例说明：缓冲区队列——假设用户输入 "abcd"，两次提取分别得到 'a' 和 'b'。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 预期输出：
//   You entered: a
//   You entered: b

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin doesn't ask the user for input, but reads remaining input
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
