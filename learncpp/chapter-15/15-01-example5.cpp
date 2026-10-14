// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：Calc 的成员函数都返回 void，因此无法"链式调用"——
//           calc.add(5).sub(3) 会编译失败（void 无成员可调）。
//           本文件用三次独立调用达到同样效果，输出 8。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：8
// 备注：本节代码为按原文示例忠实重建。
// ============================================================
#include <iostream>

class Calc
{
private:
    int m_value{};

public:
    void add(int value) { m_value += value; }
    void sub(int value) { m_value -= value; }
    void mult(int value) { m_value *= value; }

    int getValue() const { return m_value; }
};

int main()
{
    Calc calc{};
    calc.add(5);  // 返回 void
    calc.sub(3);  // 返回 void
    calc.mult(4); // 返回 void

    std::cout << calc.getValue() << '\n';

    return 0;
}
