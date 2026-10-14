// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：异常对象需要有拷贝能力——抛出时编译器会把异常对象拷贝到调用栈
//           之外的某处保存。这里 Derived 的拷贝构造函数被 = delete，于是
//           `throw d;` 无法拷贝，编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期错误：编译错误——use of deleted function 'Derived::Derived(const Derived&)'
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived : public Base
{
public:
    Derived() {}

    Derived(const Derived&) = delete; // not copyable
};

int main()
{
    Derived d{};

    try
    {
        throw d; // compile error: Derived copy constructor was deleted
    }
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived";
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base";
    }

    return 0;
}
