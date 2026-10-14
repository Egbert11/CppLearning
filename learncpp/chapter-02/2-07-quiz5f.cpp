// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #5f —— 有一个多余的两参数前置声明，但从未被使用，因此编译并链接成功。
//           预期输出：3 + 4 + 5 = 12
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-quiz5f.cpp -o a

#include <iostream>

int add(int x, int y); // an unused 2-parameter forward declaration

int add(int x, int y, int z)
{
    return x + y + z;
}

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}
