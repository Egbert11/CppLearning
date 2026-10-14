// 来源小节：11.x Chapter 11 summary and quiz（复习示例 5）
// 示例说明：函数模板 mult<T>，第一个参数为模板类型 T、第二个参数为普通 int，返回类型为 T
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：
// 6
// 3.6

#include <iostream>

template <typename T>
T mult(T x, int y)
{
    return x * y;
}

int main()
{
    std::cout << mult(2, 3) << '\n';      // mult<int>    -> 6
    std::cout << mult(1.2, 3) << '\n';    // mult<double> -> 3.6

    return 0;
}
