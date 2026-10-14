// ============================================================
// 来源小节：24.5 Inheritance and access specifiers（原 Example 2）
// 示例说明：演示【预期编译失败】的非法访问——
//           ① 派生类试图访问基类的 private 成员；
//           ② 外部代码试图访问基类的 protected / private 成员。
//           以下每一处都会各自产生编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
// 预期错误（g++ 报错信息类似）：
//   error: 'int Base::m_private' is private within this context
//   error: 'int Base::m_protected' is protected within this context
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_public{};
protected:
    int m_protected{};
private:
    int m_private{};
};

class Derived : public Base
{
public:
    Derived()
    {
        m_public = 1;       // allowed
        m_protected = 2;    // allowed
        m_private = 3;      // ERROR: cannot access private base member from derived class
    }
};

int main()
{
    Base base;
    base.m_public = 1;      // allowed
    base.m_protected = 2;   // ERROR: cannot access protected member from outside class
    base.m_private = 3;     // ERROR: cannot access private member from outside class

    return 0;
}
