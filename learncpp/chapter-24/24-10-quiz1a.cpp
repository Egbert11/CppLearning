// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 1a 解答）
// 示例说明：Base / Derived 的构造、析构函数各自打印名字。局部对象 Derived d
//           先构造基类部分再构造派生类部分，析构则相反。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出：
//   Base()
//   Derived()
//   ~Derived()
//   ~Base()
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    Base()  { std::cout << "Base()\n"; }
    ~Base() { std::cout << "~Base()\n"; }
};

class Derived : public Base
{
public:
    Derived()  { std::cout << "Derived()\n"; }
    ~Derived() { std::cout << "~Derived()\n"; }
};

int main()
{
    Derived d;

    return 0;
}
