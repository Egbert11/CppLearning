// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 4）
// 示例说明：直接对对象调用总是用该对象自己的类型；把 C 拷贝进一个 A 对象会发生切片，
//           此后调用的永远是 A::getName()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   c is a C
//   a is a A
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
    std::cout << "c is a " << c.getName() << '\n'; // calls C::getName()

    A a{ c }; // slices c (do not do this)
    std::cout << "a is a " << a.getName() << '\n'; // calls A::getName()

    return 0;
}
