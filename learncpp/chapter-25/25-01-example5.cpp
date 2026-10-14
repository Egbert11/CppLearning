// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（原 Example 8）
// 示例说明：用一个 const Animal* 数组把不同派生类型的对象放在一起。
//           数组本身只能存一种类型，基类指针让异构容器成为可能，
//           但 speak() 仍非虚，所以全部输出 "???"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出（六行，全部 says ???）：
//   Fred says ???
//   Garbo says ???
//   Misty says ???
//   Pooky says ???
//   Truffle says ???
//   Zeke says ???
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
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

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };
    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // An array of pointers to an Animal can hold all the derived types together
    const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}
