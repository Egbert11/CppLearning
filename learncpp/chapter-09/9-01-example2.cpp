// 来源小节：9.1 Introduction to testing your code
// 示例说明：正式函数 isLowerVowel() 加上 main() 里一段临时的测试代码，
//           通过调用并观察输出来验证函数行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
//
// 编译：g++ -std=c++20 -Wall 9-01-example2.cpp -o a
// 预期输出：
//   1
//   0
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

int main()
{
    // A reminder that you could put this test code in a function and call it "testVowel"
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0

    return 0;
}
