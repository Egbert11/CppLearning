// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 7-10）
// 示例说明：重载隐藏问题。基类有 print(int) 与 print(double)。派生类【新增】一个
//           print(double) 后，名字 print 在派生类中已存在，重载决议只看派生类的 print，
//           于是基类的 print(int) 被隐藏。加上 using Base::print; 后，基类的所有 print
//           重载重新可见，d.print(5) 又能解析到 Base::print(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：
//   Base::print(int)
//   Derived::print(double)
// 备注：本节代码为按原文描述重建。若去掉 using Base::print; 那行，d.print(5) 将调用
//       Derived::print(double)（基类的 int 版本被隐藏）。
// ============================================================
#include <iostream>

class Base
{
public:
    void print(int x) const { std::cout << "Base::print(int)\n"; }
    void print(double d) const { std::cout << "Base::print(double)\n"; }
};

class Derived : public Base
{
public:
    using Base::print; // make all Base::print functions visible to Derived

    void print(double d) const { std::cout << "Derived::print(double)\n"; } // this function added
};

int main()
{
    Derived d;
    d.print(5);   // resolves to Base::print(int) thanks to the using declaration
    d.print(3.5); // resolves to Derived::print(double)

    return 0;
}
