// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：Quiz #1 解答——用指针与指针算术逐字符打印 C 风格字符串。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：Hello world!
// ============================================================
#include <iostream>

// str will point to the first letter of the C-style string.
// Note that str points to a const char, so we can not change the values it points to.
// However, we can point str at something else.  This does not change the value of the argument.
void printCString(const char str[])
{
    // While we haven't encountered a null terminator
    while (*str != '\0')
    {
        // print the current character
        std::cout << *str;

        // and use pointer arithmetic to move str to the next character
        ++str;
    }
}

int main()
{
    printCString("Hello world!");

    std::cout << '\n';

    return 0;
}
