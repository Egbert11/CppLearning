// 来源小节：27.6 Rethrowing exceptions
// 示例说明：对象切片演示——catch (Base&) 捕获到真正的 Derived 对象后，
//           用 `throw b;` 重抛，b 的静态类型是 Base，于是只抛出被切掉派生部分的 Base 对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
// 预期输出：
//   Caught Base b, which is actually a Derived
//   Caught Base b, which is actually a Base
//   （第二行说明对象确实被切片了）

#include <iostream>
class Base
{
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived: public Base
{
public:
    Derived() {}
    void print() override { std::cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch (Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << '\n';
            throw b; // the Derived object gets sliced here
        }
    }
    catch (Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << '\n';
    }

    return 0;
}
