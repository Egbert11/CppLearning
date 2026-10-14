// 来源小节：4.11 Chars
// 示例说明：输入一个字符——char 变量只提取一个字符。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 示例交互：
//   Input a keyboard character: q
//   You entered: q

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "q"

    char ch{};
    std::cin >> ch; // ch = 'q', but 'q' is still in the input buffer
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
