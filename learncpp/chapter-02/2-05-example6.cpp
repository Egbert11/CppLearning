// 来源小节：2.5 Introduction to local scope
// 示例说明：与上一例相同，但 main 把自己的变量也命名为 x、y，演示不同函数可各自命名、
//           作用域不重叠，编译器不会混淆。
//           预期输出：11
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example6.cpp -o a

#include <iostream>

int add(int x, int y) // add's x and y are created and enter scope here
{
    // add's x and y are visible and usable within this function only
    return x + y;
} // add's y and x go out of scope and are destroyed here

int main()
{
    int x{ 5 }; // main's x enters scope here and can be used within main()
    int y{ 6 }; // main's y enters scope here and can be used within main()

    std::cout << add(x, y) << '\n'; // call to add() with main's x and y

    return 0;
} // main's y and x go out of scope and are destroyed here
