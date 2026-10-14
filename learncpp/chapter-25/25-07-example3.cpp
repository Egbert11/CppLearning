// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：改动前的设计——Animal 提供有默认返回值 "???" 的虚函数 speak()，
//           派生类若忘记 override 就会静默继承这个占位行为。
// 预期输出：
//   Fred says Meow
//   Rex says Woof
// 代码为原文逐字提取；末尾的 main() 为补充（原文此片段没有 main）。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name {};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

public:
    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }

    virtual ~Animal() = default;
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const override { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const override { return "Woof"; }
};

// --- 以下 main() 为补充，用于演示（原文此片段无 main）---
int main()
{
    Cat cat{ "Fred" };
    Dog dog{ "Rex" };

    std::cout << cat.getName() << " says " << cat.speak() << '\n';
    std::cout << dog.getName() << " says " << dog.speak() << '\n';

    return 0;
}
