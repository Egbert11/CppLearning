// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 11 —— #define FOO 9 之后的替换行为：
//           指令里的 FOO 不被替换，普通代码里的 FOO 被替换为 9。预期输出：9
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example11.cpp -o a

#include <iostream>

#define FOO 9 // Here's a macro substitution

int main()
{
#ifdef FOO // This FOO does not get replaced because it's part of a preprocessor command
    std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
#endif

    return 0;
}
