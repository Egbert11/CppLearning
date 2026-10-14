// 来源小节：11.x Chapter 11 summary and quiz（复习示例 7）
// 示例说明：模板 count(T) 使用函数内 static 局部变量；每个实例化有自己的 c 副本
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：1 2 1 2

#include <iostream>

template <typename T>
int count(T) // 形参未命名，因为我们不需要它
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1) << ' ';         // count<int>    -> 1
    std::cout << count(1) << ' ';         // count<int>    -> 2
    std::cout << count(2.3) << ' ';       // count<double> -> 1（独立副本）
    std::cout << count<double>(1) << ' '; // count<double>，实参转换 -> 2
    std::cout << '\n';

    return 0;
}
