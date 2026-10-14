// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（Quiz 1 解答）
// 示例说明：把"每种动物发出的声音"改为 Animal 的成员 m_speak，由派生类构造函数传入，
//           这样通过基类指针也能取到正确的声音。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出：
//   Fred says Meow
//   Garbo says Woof
//   Misty says Meow
//   Pooky says Woof
//   Truffle says Woof
//   Zeke says Meow
// 备注：本节代码为按原文描述重建；删除拷贝是为了防止对象切片（后续小节讲解）。
// ============================================================
#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name, std::string_view speak)
        : m_name{ name }, m_speak{ speak }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    const std::string& getName() const { return m_name; }
    const std::string& speak() const { return m_speak; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name, "Meow" }
    {
    }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name, "Woof" }
    {
    }
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };
    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals) // animal is not a reference, because we're looping over pointers
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}
