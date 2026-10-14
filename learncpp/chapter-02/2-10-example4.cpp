// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 4 —— 不带替换文本的对象式宏（#define USE_YEN）。
//           这种宏的名字本身被"替换为空"，常用于条件编译开关。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example4.cpp -o a

#include <iostream>

#define USE_YEN // object-like macro without substitution text

int main()
{
#ifdef USE_YEN
    std::cout << "Use yen\n"; // 只有 USE_YEN 被定义时才会编译这一行
#endif

    return 0;
}
