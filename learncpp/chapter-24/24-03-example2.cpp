// ============================================================
// 来源小节：24.3 Order of construction of derived classes（原 Example 5 / 6）
// 示例说明：四级继承链 A ← B ← C ← D，每个类的构造函数都打印自己的名字，
//           演示沿继承链逐级、自顶向下（最基类先）构造。
// 原文链接：https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/
// 预期输出：
//   Constructing A:
//   A
//   Constructing B:
//   A
//   B
//   Constructing C:
//   A
//   B
//   C
//   Constructing D:
//   A
//   B
//   C
//   D
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C : public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D : public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};

int main()
{
    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;

    return 0;
}
