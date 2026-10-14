// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 1d 解答）
// 示例说明：把 1c 中 Base 的 m_x 改为 protected 后即可编译。Derived::print()
//           能访问受保护的基类成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出：
//   Base()
//   Derived()
//   Derived: 5
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
        std::cout << "Derived: " << m_x << '\n'; // okay: m_x is protected in Base
    }
};

int main()
{
    Derived d{ 5 };
    d.print();

    return 0;
}
