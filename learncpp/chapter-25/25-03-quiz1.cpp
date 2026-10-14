// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（Quiz 1 解答）
// 示例说明：非虚 print()/虚 vprint() 混合，以及协变返回类型 get()。
//           D::get() 协变返回 B&（C::get() 声明返回 A&）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期输出：
//   BB
//   AA
//   AB
// 解析：case1 d.get() 静态类型为 B&，print/vprint 都走 B；
//       case2 c.get() 静态类型为 A&，都走 A；
//       case3 ref.get() 虚解析到 D::get()，但返回类型静态上是 A&，
//             故非虚 print() 走 A::print()，虚 vprint() 按动态类型 B 走 B::vprint()。
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class A
{
public:
    void print() { std::cout << "A"; }          // note: not virtual
    virtual void vprint() { std::cout << "A"; } // note: virtual
};

class B : public A
{
public:
    void print() { std::cout << "B"; }          // hides A::print()
    void vprint() override { std::cout << "B"; }
};

class C
{
private:
    A m_a{};

public:
    virtual A& get() { return m_a; }
};

class D : public C
{
private:
    B m_b{};

public:
    B& get() override { return m_b; } // covariant return type: B& is-a A&
};

int main()
{
    D d{};
    d.get().print();  // B
    d.get().vprint(); // B
    std::cout << '\n';

    C c{};
    c.get().print();  // A
    c.get().vprint(); // A
    std::cout << '\n';

    C& ref{ d };
    ref.get().print();  // A (static type A&, non-virtual print)
    ref.get().vprint(); // B (virtual, dynamic type B)
    std::cout << '\n';

    return 0;
}
