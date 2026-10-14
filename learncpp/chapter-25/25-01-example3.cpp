// ============================================================
// 来源小节：25.1 Pointers and references to the base class of derived objects（原 Example 3）
// 示例说明：Animal/Cat/Dog 层级。用 const Animal* 指向 Cat/Dog 对象时，
//           调用的仍是 Animal::speak()（此节 speak() 还不是虚函数），输出 "???"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/
// 预期输出：
//   cat is named Fred, and it says Meow
//   dog is named Garbo, and it says Woof
//   pAnimal is named Fred, and it says ???
//   pAnimal is named Garbo, and it says ???
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    // To prevent slicing (covered later)
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
    const Cat cat{ "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog{ "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    const Animal* pAnimal{ &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    return 0;
}
