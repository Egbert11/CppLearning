// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：用 reset() 成员函数把对象恢复默认状态。构造函数只用于
//           初始化新对象，不应直接调用；要重置已有对象，就用
//           `*this = {};`（值初始化一个临时对象再覆盖当前对象）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：先 8，再 0
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
    void reset() { *this = {}; } // 值初始化一个新对象并覆盖当前隐式对象
};

int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // 0

    return 0;
}
