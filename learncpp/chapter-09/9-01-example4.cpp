// 来源小节：9.1 Introduction to testing your code
// 示例说明：自动化测试函数——testVowel() 返回第一个失败测试的编号，全部通过时返回 0；
//           main() 据此打印失败信息或 "testVowel() tests passed."。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
//
// 编译：g++ -std=c++20 -Wall 9-01-example4.cpp -o a
// 预期输出：testVowel() tests passed.
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

// returns the number of the test that failed, or 0 if all tests passed
int testVowel()
{
    if (!isLowerVowel('a')) return 1;
    if (!isLowerVowel('e')) return 2;
    if (!isLowerVowel('i')) return 3;
    if (!isLowerVowel('o')) return 4;
    if (!isLowerVowel('u')) return 5;
    if (isLowerVowel('q')) return 6;

    return 0; // if we made it to here, all tests passed
}

int main()
{
    int result{ testVowel() };
    if (result != 0)
        std::cout << "testVowel() test " << result << " failed.\n";
    else
        std::cout << "testVowel() tests passed.\n";

    return 0;
}
