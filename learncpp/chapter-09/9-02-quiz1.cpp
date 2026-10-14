// 来源小节：9.2 Code coverage（测验题）
// 示例说明：测验题中的 isLowerVowel(char c, bool yIsVowel)。这个函数要完整覆盖
//           需要四次测试：一次命中 a/e/i/o/u，一次命中 default，
//           以及 ('y', true) 和 ('y', false) 各一次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/code-coverage/
//
// 编译：g++ -std=c++20 -Wall 9-02-quiz1.cpp -o a
// 预期输出：
//   1
//   1
//   0
//   0
//
// 本节代码为按原文描述重建。

#include <iostream>

bool isLowerVowel(char c, bool yIsVowel)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    case 'y':
        return yIsVowel;
    default:
        return false;
    }
}

int main()
{
    // The four tests needed for full coverage
    std::cout << isLowerVowel('a', false) << '\n'; // covers a/e/i/o/u -> 1
    std::cout << isLowerVowel('y', true)  << '\n'; // covers ('y', true)  -> 1
    std::cout << isLowerVowel('y', false) << '\n'; // covers ('y', false) -> 0
    std::cout << isLowerVowel('b', true)  << '\n'; // covers default      -> 0

    return 0;
}
