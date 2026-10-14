// 来源小节：9.1 Introduction to testing your code
// 示例说明：进阶版 testVowel()——用 assert() 代替"返回失败编号"的做法，并加上
//           #ifdef NDEBUG 守卫：若断言被编译掉（release 构建），打印提示并调用 std::abort()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
//
// 编译：g++ -std=c++20 -Wall 9-01-example5.cpp -o a
// 预期输出：All tests succeeded
//
// 本节代码为按原文描述重建。

#include <cassert>  // for assert
#include <cstdlib>  // for std::abort
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

// A better test function using asserts
void testVowel()
{
#ifdef NDEBUG
    // If NDEBUG is defined, asserts are compiled out.
    // Ensure asserts are enabled, otherwise this test does nothing.
    std::cerr << "This function requires asserts to be enabled. Please recompile with them on.\n";
    std::abort();
#endif

    // We can use assert() to check our function works as expected
    assert(isLowerVowel('a'));
    assert(isLowerVowel('e'));
    assert(isLowerVowel('i'));
    assert(isLowerVowel('o'));
    assert(isLowerVowel('u'));
    assert(!isLowerVowel('b'));
    assert(!isLowerVowel('q'));
    assert(!isLowerVowel('y'));
    assert(!isLowerVowel('z'));
}

int main()
{
    testVowel();

    // If we made it here, we passed all the tests
    std::cout << "All tests succeeded\n";

    return 0;
}
