// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：给 lambda 显式写上尾置返回类型 -> double，使得两个分支都能隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   2
//   2.5

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    auto divide{ [](int x, int y, bool bInteger) -> double {
        if (bInteger)
            return x / y; // result of int division implicitly converted to double
        else
            return static_cast<double>(x) / y;
    } };
    // --- 原文示例片段结束 ---

    std::cout << divide(10, 4, true) << '\n';  // 2
    std::cout << divide(10, 4, false) << '\n'; // 2.5

    return 0;
}
