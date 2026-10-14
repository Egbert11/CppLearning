// 来源小节：11.x Chapter 11 summary and quiz（复习示例 6）
// 示例说明：函数模板 sub<T, U>，两个独立模板类型参数、auto 返回类型，做减法
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：
// 1
// 1.5
// 2.5

#include <iostream>

template <typename T, typename U>
auto sub(T x, U y)
{
    return x - y;
}

// C++20 缩写函数模板的等价写法：auto sub(auto x, auto y) { return x - y; }

int main()
{
    std::cout << sub(3, 2) << '\n';     // 1
    std::cout << sub(3.5, 2) << '\n';   // 1.5
    std::cout << sub(4, 1.5) << '\n';   // 2.5

    return 0;
}
