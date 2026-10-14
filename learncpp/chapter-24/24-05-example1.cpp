// ============================================================
// 来源小节：24.5 Inheritance and access specifiers（原 Example 2 / 4）
// 示例说明：Base 有 public / protected / private 三种成员。Derived 公有继承后
//           可以访问继承为 public 与 protected 的成员，但不能访问 private 成员；
//           外部代码只能访问 public 成员。原文中的"不允许"行以注释保留。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
// 预期输出：
//   Derived sees: 1 2
// 备注：本节代码为按原文描述重建。注释中被注释掉的非法行，若取消注释会编译失败。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_public{};                  // can be accessed by anybody
protected:
    int m_protected{};               // can be accessed by Base members, friends, and derived classes
private:
    int m_private{};                 // can only be accessed by Base members and friends (but not derived classes)
};

class Derived : public Base
{
public:
    Derived()
    {
        m_public = 1;       // allowed: can access public base members from derived class
        m_protected = 2;    // allowed: can access protected base members from derived class
        // m_private = 3;   // not allowed: can not access private base members from derived class
    }

    void show() const
    {
        std::cout << "Derived sees: " << m_public << ' ' << m_protected << '\n';
    }
};

int main()
{
    Base base;
    base.m_public = 1;      // allowed: can access public members from outside class
    // base.m_protected = 2;   // not allowed: can not access protected members from outside class
    // base.m_private = 3;     // not allowed: can not access private members from outside class

    Derived derived;
    derived.show();

    return 0;
}
