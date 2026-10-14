// 来源小节：11.x Chapter 11 summary and quiz（复习示例 4）
// 示例说明：函数模板 add<T>(T, T)，对相同类型的两值求和
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：
// 5
// 4.6

#include <iostream>

template <typename T>
T add(T x, T y)
{
    return x + y;
}

int main()
{
    std::cout << add(2, 3) << '\n';       // add<int>    -> 5
    std::cout << add(1.2, 3.4) << '\n';   // add<double> -> 4.6

    return 0;
}
