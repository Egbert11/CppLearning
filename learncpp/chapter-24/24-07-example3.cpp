// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 4）
// 示例说明：在派生类重新定义的 identify() 里，用作用域解析 Base::identify()
//           显式调用基类版本，从而"在既有功能之上追加"，而不是替换掉它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：
//   Base::identify()
//   Derived::identify()
//   Base::identify()
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base
{
public:
    void identify() const
    {
        std::cout << "Derived::identify()\n";
        Base::identify(); // call the base class version explicitly
    }
};

int main()
{
    Base base;
    base.identify();

    Derived derived;
    derived.identify();

    return 0;
}
