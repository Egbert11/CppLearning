// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（原 Example 2）
// 示例说明：Base& / Base* 可以合法地绑定到 Derived 对象，但只能"看到"Base 部分，
//           因此 getName() 调用的是 Base::getName()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出：
//   derived is a Derived and has value 5
//   rBase is a Base and has value 5
//   pBase is a Base and has value 5
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

    std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    std::string_view getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};

int main()
{
    Derived derived { 5 };

    // These are both legal!
    Base& rBase { derived };  // rBase is an lvalue reference to a Base
    Base* pBase { &derived }; // pBase is a pointer to a Base

    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    // A Base reference/pointer sees only the Base part of the object
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    return 0;
}
