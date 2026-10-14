// 来源小节：27.6 Rethrowing exceptions
// 示例说明：重抛异常的"正确方式"——在 catch 中用单独的 `throw;` 原样重抛同一个异常对象，
//           不发生拷贝，也不会切片。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
// 预期输出：
//   Caught Base b, which is actually a Derived
//   Caught Base b, which is actually a Derived
//   （第二行仍是 Derived，说明对象未被切片）

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
            throw; // note: We're now rethrowing the object here
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
