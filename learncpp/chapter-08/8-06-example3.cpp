// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：用重复的逻辑或比较判断字符是否为元音。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example3.cpp -o a
//
// 本节代码为按原文描述重建（原文为函数片段，此处补 main）。

#include <iostream>

bool isVowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << isVowel('a') << '\n'; // true
    std::cout << isVowel('B') << '\n'; // false

    return 0;
}
