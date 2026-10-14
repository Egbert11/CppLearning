// 来源小节：11.6 Function templates
// 示例说明：只处理 int 的 max 函数——演示固定形参类型带来的限制。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates/
//
// 编译：g++ -std=c++20 -Wall 11-06-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int max(int x, int y)
{
    return (x < y) ? y : x;
    // Note: we use < instead of > because std::max uses <
}

int main()
{
    std::cout << max(1, 2) << '\n'; // 2

    return 0;
}
