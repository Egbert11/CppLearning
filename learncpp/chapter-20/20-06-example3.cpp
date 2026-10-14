// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：把 lambda 存进一个变量（auto），给它一个有用的名字以便复用与阅读。
//           Key insight：存储 lambda 到变量能给它一个可读的名字，并允许复用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出（数组含奇数，所以 all_of 为假）：
//   Not all the elements are even
//   Inline: not all the elements are even

#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr{ 13, 90, 99, 5, 40, 80 };

    // --- 原文示例片段 ---
    // A lambda has no explicitly usable type; the compiler generates a unique,
    // unexposed type for each lambda. Storing it in an auto variable gives us a
    // name and lets us reuse it.
    auto isEven{ [](int i) { return (i % 2) == 0; } };

    if (std::all_of(arr.begin(), arr.end(), isEven))
        std::cout << "All the elements are even\n";
    else
        std::cout << "Not all the elements are even\n";
    // --- 原文示例片段结束 ---

    // The same thing inline, without a named variable:
    if (std::all_of(arr.begin(), arr.end(), [](int i) { return (i % 2) == 0; }))
        std::cout << "Inline: all the elements are even\n";
    else
        std::cout << "Inline: not all the elements are even\n";

    return 0;
}
