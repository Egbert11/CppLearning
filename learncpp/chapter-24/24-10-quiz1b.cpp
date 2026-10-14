// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 1b 解答）
// 示例说明：在 1a 基础上再加一个局部对象 Base b。提示：局部变量按定义的相反
//           顺序销毁，所以 b 先于 d 被销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出：
//   Base()
//   Derived()
//   Base()
//   ~Base()
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
    Base b;

    return 0;
}
