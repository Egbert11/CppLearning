// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：把 Animal::speak() 改为纯虚函数后，Animal 成为抽象基类；
//           Cow 仍未重写 speak()，于是 Cow 也是抽象类，无法实例化。
// 预期错误（原文给出的 GCC 输出）：
//   error: variable type 'Cow' is an abstract class
//   note: unimplemented pure virtual method 'speak' in 'Cow'
//   编译命令：g++ -std=c++20 -Wall 25-07-example5-error.cpp
//   该文件按设计无法编译，请勿修复。
// 代码为原文逐字提取（Animal 定义取自原文 Example 5，Cow/main 取自 Example 6）。
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
        : Animal{ name }
    {
    }

    // We forgot to redefine speak
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}
