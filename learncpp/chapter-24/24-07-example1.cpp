// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 1 / 2）
// 示例说明：Base 定义了 identify()，Derived 未定义任何东西时，derived.identify()
//           会调用继承来的基类版本；当 Derived 重新定义 identify() 后，改为调用
//           自己的版本，行为于是不同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：
//   Base::identify()
//   Derived::identify()
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
    void identify() const { std::cout << "Derived::identify()\n"; }
};

int main()
{
    Base base;
    base.identify();

    Derived derived;
    derived.identify();

    return 0;
}
