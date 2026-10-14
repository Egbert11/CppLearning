// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：Cow 正确重写了纯虚函数 speak()，于是 Cow 不再是抽象类，可以实例化。
// 预期输出：Betsy says Moo
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name {};

public:
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

class Cow: public Animal
{
public:
    Cow(std::string_view name)
        : Animal(name)
    {
    }

    std::string_view speak() const override { return "Moo"; }
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}
