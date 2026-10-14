// 来源小节：1.4 Variable assignment and initialization
// 示例说明：先定义变量、再对它赋值，然后重新赋值以演示"旧值被覆盖"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 预期输出：
//   57

#include <iostream>

int main()
{
    int width; // define a variable named width
    width = 5; // copy assignment of value 5 into variable width

    std::cout << width; // prints 5

    width = 7; // change value stored in variable width to 7

    std::cout << width; // prints 7

    return 0;
}
