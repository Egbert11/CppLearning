// 来源小节：21.10 Overloading the parenthesis operator
// 示例说明：仿函数（functor）——重载 operator() 使对象“用起来像函数”，
//           其优势是可以携带数据成员。Accumulator 累计传入的值并返回当前总和。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   1
//   4
//   10
//   30

#include <iostream>

class Accumulator
{
private:
    int m_counter{ 0 };

public:
    int operator() (int i) { return (m_counter += i); }

    void reset() { m_counter = 0; } // optional
};

int main()
{
    // --- 原文示例片段 ---
    Accumulator acc{};
    std::cout << acc(1) << '\n'; // prints 1
    std::cout << acc(3) << '\n'; // prints 4

    Accumulator acc2{};
    std::cout << acc2(10) << '\n'; // prints 10
    std::cout << acc2(20) << '\n'; // prints 30
    // --- 原文示例片段结束 ---

    return 0;
}
