// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 6）
// 示例说明：与上一示例结构相同，但 speak() 声明为 virtual，于是通过基类引用调用
//           也能解析到最派生的版本，输出 Meow / Woof —— 这就是多态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   Fred says Meow
//   Garbo says Woof
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
    virtual std::string_view speak() const { return "???"; } // note: virtual
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
