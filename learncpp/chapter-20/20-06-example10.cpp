// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：<functional> 提供的标准库函数对象 std::greater，可替代手写 lambda。
//           注意 std::greater{} 的花括号——需要实例化一个对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：99 90 80 40 13 5（三次排序结果相同）

#include <algorithm>
#include <array>
#include <functional> // for std::greater
#include <iostream>

// --- 原文示例片段 ---
bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return a > b;
}
// --- 原文示例片段结束 ---

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass greater to std::sort (a normal function)
    std::sort(arr.begin(), arr.end(), greater);
    for (int i : arr)
        std::cout << i << ' ';
    std::cout << '\n';

    // --- 原文示例片段 ---
    // Using a lambda instead of a named function
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });
    // --- 原文示例片段结束 ---
    for (int i : arr)
        std::cout << i << ' ';
    std::cout << '\n';

    // --- 原文示例片段 ---
    // Using the standard library function object
    std::sort(arr.begin(), arr.end(), std::greater{}); // note: the curly braces to instantiate std::greater object
    // --- 原文示例片段结束 ---
    for (int i : arr)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
