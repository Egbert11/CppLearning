// 来源小节：20.3 Recursion
// 示例说明：用记忆化（memoization）把斐波那契变高效：用一个 static vector 缓存已算结果，
//           避免重复计算。原文对比：朴素版要 1205 次调用，记忆化版只要 35 次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/recursion/
// 说明：本节代码为按原文描述重建。
// 预期输出：0 1 1 2 3 5 8 13 21 34 55 89 144

#include <iostream>
#include <vector>

// --- 原文示例片段 ---
int fibonacci(std::size_t count)
{
    if (count == 0)
        return 0;
    if (count == 1)
        return 1;

    static std::vector results{ 0, 1 }; // a static vector to cache results

    // If we've already calculated this value, return it
    if (count < std::size(results))
        return results[count];

    // Otherwise calculate the value and store it
    results.push_back(fibonacci(count - 1) + fibonacci(count - 2));

    return results[count];
}
// --- 原文示例片段结束 ---

int main()
{
    for (int count{ 0 }; count < 13; ++count)
        std::cout << fibonacci(static_cast<std::size_t>(count)) << ' ';
    std::cout << '\n';

    return 0;
}
