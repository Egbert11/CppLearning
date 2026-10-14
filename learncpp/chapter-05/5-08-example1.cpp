// 来源小节：5.8 Introduction to std::string_view
// 示例说明：拷贝代价对比——基本类型 int 初始化很快；std::string 初始化会拷贝字面量（较慢）；
//           std::string 按值传参又会产生一次拷贝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 1–3）。
// 预期输出：
//   5
//   Hello, world!
//   Hello, world!

#include <iostream>
#include <string>

void printString(std::string str) // str is a copy of the std::string passed in
{
    std::cout << str << '\n';
}

int main()
{
    int x { 5 }; // 5 is copied into the memory allocated for x (fast for fundamental types)
    std::cout << x << '\n';

    std::string s{ "Hello, world!" }; // the literal is copied into s's allocated memory (slow)
    printString(s);                   // prints a copy of s

    return 0;
}
