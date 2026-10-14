// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（原 Example 1）
// 示例说明：用 Derived& 与 Derived* 绑定一个 Derived 对象，成员调用按预期解析到派生类版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出：
//   derived is a Derived and has value 5
//   rDerived is a Derived and has value 5
//   pDerived is a Derived and has value 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    std::string_view getName() const { return "Base"; } // Base 版本
    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    std::string_view getName() const { return "Derived"; } // Derived 版本
    int getValueDoubled() const { return m_value * 2; }
};

int main()
{
    Derived derived { 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Derived& rDerived { derived };
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

    Derived* pDerived { &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    return 0;
}
