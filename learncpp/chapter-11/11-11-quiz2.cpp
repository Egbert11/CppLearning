// 来源小节：11.x Chapter 11 summary and quiz（测验 2）
// 题目：写出 (1) 同类型两值相加的 add 模板；(2) 任意类型值乘 int（第二参不模板化）返回第一参类型的 mult 模板；
//       (3) 两个不同类型值相减的 sub 模板。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
// 本节代码为按原文描述重建
// 预期输出：
// 5
// 4.6
// 6
// 3.6
// 1
// 1.5
// 2.5

#include <iostream>

template <typename T>
T add(T x, T y)
{
    return x + y;
}

template <typename T>
T mult(T x, int y)
{
    return x * y;
}

template <typename T, typename U>
auto sub(T x, U y)
{
    return x - y;
}

int main()
{
    std::cout << add(2, 3) << '\n';      // 5
    std::cout << add(1.2, 3.4) << '\n';  // 4.6

    std::cout << mult(2, 3) << '\n';     // 6
    std::cout << mult(1.2, 3) << '\n';   // 3.6

    std::cout << sub(3, 2) << '\n';      // 1
    std::cout << sub(3.5, 2) << '\n';    // 1.5
    std::cout << sub(4, 1.5) << '\n';    // 2.5

    return 0;
}
