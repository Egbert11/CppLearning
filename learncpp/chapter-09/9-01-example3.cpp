// 来源小节：9.1 Introduction to testing your code
// 示例说明：把示例 2 里的临时测试搬进独立的 testVowel() 函数并保留下来（当前还没有被
//           任何地方调用），演示"保留测试以便日后再跑"的做法。main() 为空。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
//
// 编译：g++ -std=c++20 -Wall 9-01-example3.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// Not called from anywhere right now
// But here if you want to retest things later
void testVowel()
{
    std::cout << isLowerVowel('a') << '\n'; // should produce 1
    std::cout << isLowerVowel('q') << '\n'; // should produce 0
}

int main()
{
    return 0;
}
