// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：函数默认具有外部链接，可被其它文件使用。这是定义 sayHi 的源文件。
//           （对应原文 Example 1 的 a.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// 多文件示例，编译：g++ -std=c++20 -Wall 7-07-example1/*.cpp

#include <iostream>

void sayHi() // this function has external linkage, and can be seen by other files
{
    std::cout << "Hi!\n";
}
