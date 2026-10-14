// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 5）
// 示例说明：演示【坏实践】——在派生类的 identify() 里漏写了作用域限定符，直接写
//           identify(); 会再次解析到派生类自己的函数，形成自我调用 → 无限递归，
//           最终栈溢出崩溃。正确写法应为 Base::identify();（见 24-07-example3.cpp）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：不断打印 "Derived::identify()" 直到栈溢出（请勿运行本文件）。
// 备注：本节代码为按原文描述重建。坏实践演示，仅作说明，请勿运行。
// ============================================================
#include <iostream>

class Base
{
public:
    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base
{
public:
    void identify() const
    {
        std::cout << "Derived::identify()\n";
        identify(); // bad: self-call, results in infinite recursion
        // should be: Base::identify();
    }
};

int main()
{
    Derived derived;
    derived.identify(); // will recurse until the stack overflows

    return 0;
}
