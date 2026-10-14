// 来源小节：2.9 Naming collisions and an introduction to namespaces
// 示例说明：原文 Example 4 —— 使用显式命名空间前缀 std:: 访问 cout（推荐做法）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/
//
// 编译：g++ -std=c++20 -Wall 2-09-example1.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Hello world!"; // when we say cout, we mean the cout defined in the std namespace
    return 0;
}
