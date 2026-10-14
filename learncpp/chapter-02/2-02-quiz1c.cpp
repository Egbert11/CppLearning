// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：Quiz 1c —— 单独调用两个函数但不使用它们的返回值。能编译，但没有任何输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-quiz1c.cpp -o a

#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    return7(); // the return value is not used
    return9(); // the return value is not used

    return 0;
}
