// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：纯虚函数也可以有定义（此处 out-of-line 定义返回 "buzz"），
//           但类仍是抽象类，派生类仍必须重写。Dragonfly 重写时直接委托给
//           Animal::speak() 使用基类的默认实现。
// 预期输出：Sally says buzz
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
        : m_name(name)
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const = 0; // note that speak is a pure virtual function

    virtual ~Animal() = default;
};

std::string_view Animal::speak() const
{
    return "buzz"; // some default implementation
}

class Dragonfly: public Animal
{

public:
    Dragonfly(std::string_view name)
        : Animal{name}
    {
    }

    std::string_view speak() const override// this class is no longer abstract because we defined this function
    {
        return Animal::speak(); // use Animal's default implementation
    }
};

int main()
{
    Dragonfly dfly{"Sally"};
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

    return 0;
}
