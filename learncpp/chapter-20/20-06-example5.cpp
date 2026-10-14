// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：把 lambda 传给函数的四种方式：
//           1) std::function 形参（签名显式，有少量转换开销，可拆到 .h/.cpp）；
//           2) 带类型模板参数的模板（高效但签名不那么直观）；
//           3) C++20 缩写函数模板（用 auto 形参，等价于 2）；
//           4) 函数指针（只适用于无捕获的 lambda）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：0 1 2 各自打印四遍（0\n1\n2\n 重复四次）

#include <functional>
#include <iostream>

// --- 原文示例片段 ---
// Case 1: use a std::function parameter
void repeat1(int repetitions, const std::function<void(int)>& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

// Case 2: use a function template with a type template parameter
template <typename T>
void repeat2(int repetitions, const T& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

// Case 3: use the abbreviated function template syntax (C++20)
void repeat3(int repetitions, const auto& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

// Case 4: use a function pointer (only works if the lambda has no captures)
void repeat4(int repetitions, void (*fn)(int))
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}
// --- 原文示例片段结束 ---

int main()
{
    auto lambda = [](int i)
    {
        std::cout << i << '\n';
    };

    repeat1(3, lambda);
    repeat2(3, lambda);
    repeat3(3, lambda);
    repeat4(3, lambda);

    return 0;
}
