// 来源小节：2.7 Forward declarations and definitions
// 示例说明：声明中可以省略参数名（只写类型），这是合法的函数声明。
//           预期输出：The sum of 3 and 4 is: 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example5.cpp -o a

#include <iostream>

int add(int, int); // valid function declaration (parameter names omitted)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
