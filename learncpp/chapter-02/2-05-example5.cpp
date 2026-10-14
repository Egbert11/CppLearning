// 来源小节：2.5 Introduction to local scope
// 示例说明：add 与 main 的作用域互不重叠：main 用 a、b，add 用 x、y；实参被拷贝进形参。
//           预期输出：11
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example5.cpp -o a

#include <iostream>

int add(int x, int y) // add's x and y are created and enter scope here
{
    // add's x and y are visible and usable within this function only
    return x + y;
} // add's y and x go out of scope and are destroyed here

int main()
{
    int a{ 5 }; // main's a enters scope here
    int b{ 6 }; // main's b enters scope here

    // with this call to add, main's a and b are copied to add's x and y
    std::cout << add(a, b) << '\n';

    return 0;
} // main's b and a go out of scope and are destroyed here
