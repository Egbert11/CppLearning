// ============================================================
// 来源小节：24.4 Constructors and initialization of derived classes（原 Example 11）
// 示例说明：三类的继承链 A / B / C。B 向上调用 A{ a }，C 向上调用 B{ a, b }，
//           每个构造函数都先把参数转发给直接基类，再打印自己的那一部分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
// 预期输出：
//   A: 5
//   B: 4.3
//   C: R
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};

class B : public A
{
public:
    B(int a, double b)
        : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
};

class C : public B
{
public:
    C(int a, double b, char c)
        : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
};

int main()
{
    C c{ 5, 4.3, 'R' };

    return 0;
}
