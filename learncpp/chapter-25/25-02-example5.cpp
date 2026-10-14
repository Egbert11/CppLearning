// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 5）
// 示例说明：speak() 非虚时，通过基类引用调用 report() 得到的是 Animal::speak()，
//           输出 "???"（对比下一示例的虚函数版本）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
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

void report(const Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat{ "Fred" };
    report(cat);

    Dog dog{ "Garbo" };
    report(dog);

    return 0;
}
