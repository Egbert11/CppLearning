// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：Quiz #2 解答——用指针与指针算术反向打印 C 风格字符串。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：!dlrow olleH
// ============================================================
#include <iostream>

void printCStringBackwards(const char str[])
{
    // We can't modify str this time (we need it later)
    // So we'll define a new pointer with the same address as str
    const char *ptr{ str };

    // Find the null terminator
    while (*ptr != '\0')
        ++ptr;

    // Now walk backwards and print characters until ptr reaches str again
    while (ptr-- != str)
    {
        std::cout << *ptr;
    }
}

int main()
{
    printCStringBackwards("Hello world!");

    std::cout << '\n';

    return 0;
}
