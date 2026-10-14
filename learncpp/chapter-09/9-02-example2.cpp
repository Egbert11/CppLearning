// 来源小节：9.2 Code coverage
// 示例说明：带 switch 的 isLowerVowel()——需要用两次调用来触达所有语句/分支
//           （一次命中某个 case，一次命中 default）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/code-coverage/
//
// 编译：g++ -std=c++20 -Wall 9-02-example2.cpp -o a
// 预期输出：
//   1
//   0
//
// 本节代码为按原文描述重建。

#include <iostream>

bool isLowerVowel(char c)
{
    switch (c) // statement 1
    {
    case 'a':  // case a and following are statements 2-6
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    // Two calls are needed to cover every statement and branch
    std::cout << isLowerVowel('a') << '\n'; // exercises the true case
    std::cout << isLowerVowel('q') << '\n'; // exercises the default case

    return 0;
}
