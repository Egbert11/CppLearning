// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：Calc 的成员函数改为返回 *this（当前对象的引用），于是可以
//           在一条表达式里连续调用：calc.add(5).sub(3).mult(4)，
//           即 ((0 + 5) - 3) * 4 == 8。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：8
// 备注：本节代码为按原文示例忠实重建（原文给出完整代码）。
// ============================================================
#include <iostream>

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() const { return m_value; }
};

int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4); // 链式调用（method chaining）

    std::cout << calc.getValue() << '\n';

    return 0;
}
