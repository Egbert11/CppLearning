// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 1c 解答）
// 示例说明：演示【预期编译失败】——Base 的成员 m_x 是 private，而 Derived::print()
//           试图读取 m_x。派生类不能访问基类的私有成员，因此无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期错误（g++ 报错信息类似）：
//   error: 'int Base::m_x' is private within this context
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
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

private:
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
        std::cout << "Derived: " << m_x << '\n'; // ERROR: m_x is private in Base
    }
};

int main()
{
    Derived d{ 5 };
    d.print();

    return 0;
}
