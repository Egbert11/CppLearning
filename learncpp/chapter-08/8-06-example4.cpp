// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：用"堆叠的 case 标签"（stacked sequential case labels）实现同一个元音判断。
//           标签是标签而不是语句，所以多个标签共享后续语句并不算 fallthrough。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example4.cpp -o a
//
// 本节代码为按原文描述重建（原文为函数片段，此处补 main）。

#include <iostream>

bool isVowel(char c)
{
    switch (c)
    {
    case 'a': // if c is 'a'
    case 'e': // or if c is 'e'
    case 'i': // or if c is 'i'
    case 'o': // or if c is 'o'
    case 'u': // or if c is 'u'
    case 'A': // or if c is 'A'
    case 'E': // or if c is 'E'
    case 'I': // or if c is 'I'
    case 'O': // or if c is 'O'
    case 'U': // or if c is 'U'
        return true;
    default:
        return false;
    }
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << isVowel('e') << '\n'; // true
    std::cout << isVowel('z') << '\n'; // false

    return 0;
}
