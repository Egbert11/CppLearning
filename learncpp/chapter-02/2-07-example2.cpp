// 来源小节：2.7 Forward declarations and definitions
// 示例说明：方案一 —— 把 add() 的定义放到 main() 之前，调整定义顺序即可编译。
//           预期输出：The sum of 3 and 4 is: 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example2.cpp -o a

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}
