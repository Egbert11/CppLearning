// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：把同一个 lambda 用三种方式存储：(1) 函数指针（仅限无捕获的 lambda）；
//           (2) std::function；(3) auto（唯一能用 lambda 真实类型的方式，且无开销）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   3
//   7
//   11

#include <functional>
#include <iostream>

// --- 原文示例片段 ---
// Case 1: store the lambda in a function pointer
// Note: this only works when the lambda has an empty capture clause
double (*addNumbers1)(double, double){ [](double a, double b) {
    return a + b;
} };

// Case 2: store the lambda in a std::function
std::function addNumbers2{ [](double a, double b) {
    return a + b;
} };

// Case 3: store the lambda in an auto variable
// (This uses the lambda's actual type, which we can't write out directly.)
auto addNumbers3{ [](double a, double b) {
    return a + b;
} };
// --- 原文示例片段结束 ---

int main()
{
    std::cout << addNumbers1(1, 2) << '\n';
    std::cout << addNumbers2(3, 4) << '\n';
    std::cout << addNumbers3(5, 6) << '\n';

    return 0;
}
