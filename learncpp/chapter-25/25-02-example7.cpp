// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 7）
// 示例说明：一个基类指针数组装下所有派生类型；配合虚函数，每只动物都发出各自的声音，
//           无需为派生类型改动循环或容器。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   Fred says Meow
//   Garbo says Woof
//   Misty says Meow
//   Pooky says Woof
//   Truffle says Woof
//   Zeke says Meow
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

public:
    virtual ~Animal() = default;
    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const override { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const override { return "Woof"; }
};

int main()
{
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // An array of pointers to an Animal is good as a single array because
    // the pointers can point to objects of any derived type.
    Animal* animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto* animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}
