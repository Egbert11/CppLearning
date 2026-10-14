// 来源小节：5.7 Introduction to std::string
// 示例说明：std::string 基础——创建、用字面量初始化、重新赋值、输出、空字符串、
//           字符串长度可变，以及“数字样”的字符串仍是文本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 1–7）。
// 预期输出：
//   Hello, world!
//   My name is: Alex
//   My name is: John
//   []
//   45
//   Jason
//   Jay

#include <iostream>
#include <string>

int main()
{
    // "Hello world!" is a C-style string literal.
    std::cout << "Hello, world!" << '\n';

    std::string name { "Alex" };            // initialize name with string literal "Alex"
    std::cout << "My name is: " << name << '\n';

    name = "John";                          // change name to "John"
    std::cout << "My name is: " << name << '\n';

    std::string empty {};                   // empty string
    std::cout << '[' << empty << "]\n";     // prints []

    std::string myID { "45" };              // "45" is not the same as integer 45!
    std::cout << myID << '\n';

    name = "Jason";                         // change name to a longer string
    std::cout << name << '\n';
    name = "Jay";                           // change name to a shorter string
    std::cout << name << '\n';

    return 0;
}
