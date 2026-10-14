// 来源小节：2.7 Forward declarations and definitions
// 示例说明：定义示例 —— 带函数体的 add() 是函数 add 的一个实现（同时实例化了局部变量 z）；
//           int x 实例化了一个变量 x。
//           预期输出：The sum of 3 and 4 is: 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example8.cpp -o a

#include <iostream>

// --- 原文示例片段 ---
// because this function has a body, it is an implementation of function add()
int add(int x, int y)
{
    int z{ x + y };   // instantiates variable z

    return z;
}

int x;                // instantiates variable x
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}
