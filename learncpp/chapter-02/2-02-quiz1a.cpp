// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：Quiz 1a —— 两个函数的返回值在同一个表达式中相加。
//           预期输出：16
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-quiz1a.cpp -o a

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
    std::cout << return7() + return9() << '\n'; // 16

    return 0;
}
