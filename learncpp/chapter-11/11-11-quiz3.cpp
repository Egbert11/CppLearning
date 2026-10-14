// 来源小节：11.x Chapter 11 summary and quiz（测验 3）
// 题目：count(T) 模板程序的输出是什么、为什么？
// 解答：前两次调用复用 count<int>（同一个 static c，递增到 2）；count(2.3) 生成独立的
//       count<double>，其 static 从 1 开始；count<double>(1) 显式复用 double 版并把实参转换，返回 2。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：1 2 1 2

#include <iostream>

template <typename T>
int count(T)
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1) << ' ';
    std::cout << count(1) << ' ';
    std::cout << count(2.3) << ' ';
    std::cout << count<double>(1) << ' ';
    std::cout << '\n';

    return 0;
}
