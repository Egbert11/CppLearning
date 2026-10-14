// 来源小节：4.11 Chars
// 示例说明：打印字符——cout 按 ASCII 字符显示 char。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 输出：ab

#include <iostream>

int main()
{
    char ch1{ 'a' }; // preferred
    std::cout << ch1; // prints a

    char ch2{ 98 }; // 'b' (not preferred)
    std::cout << ch2; // prints b

    return 0;
}
