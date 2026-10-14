// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5e —— 声明中不带参数名，编译并链接成功（与上一例同理）。
//           预期输出：3 + 4 + 5 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5e.cpp -o a

#include <iostream>
int add(int, int, int); // no parameter names

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
