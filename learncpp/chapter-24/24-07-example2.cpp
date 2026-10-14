// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 3）
// 示例说明：访问说明符不会随重新定义而继承。Base::print() 声明为 private，
//           Derived::print() 声明为 public，于是通过派生对象调用 print() 是合法的
//           ——它使用派生类自己声明的访问级别。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：
//   Derived (public redefinition)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
private:
    void print() const { std::cout << "Base"; }
};

class Derived : public Base
{
public:
    void print() const { std::cout << "Derived (public redefinition)\n"; }
};

int main()
{
    Derived derived;
    derived.print(); // okay: Derived::print() is public

    return 0;
}
