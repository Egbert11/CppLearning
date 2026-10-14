// ============================================================
// 来源小节：24.6 Adding new functionality to a derived class（原 Example 1-4）
// 示例说明：Base 的 m_value 声明为 protected，派生类无需任何访问器即可直接使用。
//           Derived 在继承 Base 的基础上【新增】getValue()，并在 main 中通过派生
//           对象调用它——这正是"给派生类添加新功能"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/adding-new-functionality-to-a-derived-class/
// 预期输出：
//   derived has value 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    // New functionality: a function that returns m_value
    int getValue() const { return m_value; }
};

int main()
{
    Derived derived{ 5 };
    std::cout << "derived has value " << derived.getValue() << '\n';

    return 0;
}
