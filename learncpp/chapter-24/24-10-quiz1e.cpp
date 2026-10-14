// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 1e 解答）
// 示例说明：在 1d 基础上新增 D2 公开继承 Derived。D2 自身没有 print()，所以
//           d.print() 使用继承来的 Derived::print()。构造顺序 Base → Derived → D2，
//           析构顺序相反。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出：
//   Base()
//   Derived()
//   D2()
//   Derived: 5
//   ~D2()
//   ~Derived()
//   ~Base()
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    Base(int x)
        : m_x{ x }
    {
        std::cout << "Base()\n";
    }

    ~Base()
    {
        std::cout << "~Base()\n";
    }

protected:
    int m_x {};
};

class Derived : public Base
{
public:
    Derived(int z) : Base{ z }
    {
        std::cout << "Derived()\n";
    }

    ~Derived()
    {
        std::cout << "~Derived()\n";
    }

    void print()
    {
        std::cout << "Derived: " << m_x << '\n';
    }
};

class D2 : public Derived
{
public:
    D2(int z) : Derived{ z }
    {
        std::cout << "D2()\n";
    }

    ~D2()
    {
        std::cout << "~D2()\n";
    }

    // note: no print() function here
};

int main()
{
    D2 d{ 5 };
    d.print(); // uses Derived::print()

    return 0;
}
