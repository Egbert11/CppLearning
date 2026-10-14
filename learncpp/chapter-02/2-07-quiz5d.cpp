// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5d —— 定义中参数名与声明不同，但类型一致；参数名不是声明的一部分，
//           编译器会忽略，因此编译并链接成功。
//           预期输出：3 + 4 + 5 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5d.cpp -o a

#include <iostream>
int add(int x, int y, int z);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int z, int y, int x) // names don't match the declaration
{
    return x + y + z;
}
