// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（原 Example 5）
// 示例说明：用单个 report(const Animal&) 取代每个派生类型一个重载。
//           好处是任何现有/未来的派生类都能直接传入，但由于 speak() 非虚，
//           它调用的仍是 Animal::speak()，输出 "???"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出：
//   Fred says ???
//   Garbo says ???
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name;

    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    const std::string& getName() const { return m_name; }
    std::string_view speak() const { return "???"; } // note: not virtual
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Woof"; }
};

// A single function that takes a reference to an Animal (the base class)
// This replaces the need for one overloaded report() per derived type.
void report(const Animal& rAnimal)
{
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}

int main()
{
    const Cat cat{ "Fred" };
    const Dog dog{ "Garbo" };

    report(cat);
    report(dog);

    return 0;
}
