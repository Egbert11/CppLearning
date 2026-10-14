// 来源小节：20.3 Recursion
// 示例说明：经典的（低效的）递归斐波那契数列。F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)。
//           简单但指数级重复计算。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出：0 1 1 2 3 5 8 13 21 34 55 89 144

#include <iostream>

// --- 原文示例片段 ---
int fibonacci(int count)
{
    if (count == 0)
        return 0; // base case (termination condition)
    if (count == 1)
        return 1; // base case (termination condition)
    return fibonacci(count - 1) + fibonacci(count - 2);
}
// --- 原文示例片段结束 ---

int main()
{
    for (int count{ 0 }; count < 13; ++count)
        std::cout << fibonacci(count) << ' ';
    std::cout << '\n';

    return 0;
}
