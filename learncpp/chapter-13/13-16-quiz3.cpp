// ============================================================
// 来源小节：13.x Chapter 13 summary and quiz（本仓库文件号 13-16）
// 示例说明：测验 3 解答——Triad 类模板 + 推导指引 + print 函数模板，使用 CTAD。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/
// 备注：本节代码为按原文清单与站点标准写法重建。
// ============================================================
#include <iostream>

template <typename T>
struct Triad
{
    T first{};
    T second{};
    T third{};
};

// Deduction guide so that Triad can be used with CTAD (C++17)
// Triad objects initialized with three arguments of type T should deduce to Triad<T>
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& t)
{
    std::cout << '[' << t.first << ", " << t.second << ", " << t.third << ']';
}

int main()
{
    Triad t1{ 1, 2, 3 };        // note: uses CTAD to deduce Triad<int>
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };  // note: uses CTAD to deduce Triad<double>
    print(t2);

    std::cout << '\n';

    return 0;
}

// 预期输出：
// [1, 2, 3][1.2, 3.4, 5.6]
