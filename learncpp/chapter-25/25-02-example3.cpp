// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 3）
// 示例说明：四级继承 A->B->C->D。用 A& 绑定一个 C 对象，虚函数解析到 C::getName()
//           （处于静态类型 A 与动态类型 C 之间的那一版）；D::getName() 不在考虑范围内。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   rBase is a C
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class A
{
public:
    virtual ~A() = default;
    virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
    std::string_view getName() const override { return "B"; }
};

class C : public B
{
public:
    std::string_view getName() const override { return "C"; }
};

class D : public C
{
public:
    std::string_view getName() const override { return "D"; }
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
