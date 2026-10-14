// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（原 Example 5）
// 示例说明：协变返回类型。Derived::getThis() 返回 Derived*，Base::getThis() 返回 Base*。
//           通过 Base* 调用时虚函数解析到 Derived::getThis()，但返回类型被向上转成 Base*，
//           于是随后的非虚 printType() 调用的是 Base::printType()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期输出：
//   called Derived::getThis()
//   returned a Derived
//   called Derived::getThis()
//   returned a Base
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    virtual ~Base() = default;
    virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
    void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
    Derived* getThis() override { std::cout << "called Derived::getThis()\n"; return this; } // covariant return type
    void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
    Derived d{};
    Base* b{ &d };

    d.getThis()->printType();  // calls Derived::getThis(), returns a Derived*, calls Derived::printType()
    b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType()

    return 0;
}
