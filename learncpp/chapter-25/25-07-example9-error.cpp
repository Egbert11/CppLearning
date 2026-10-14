// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：Visual Studio 允许在纯虚函数声明处内联给出函数体——这是不符合
//           C++ 标准的扩展。此处用于演示：GCC/Clang 会报编译错误。
// 预期错误：error: pure-specifier on function-definition（纯虚说明符与函数体不能并存）。
//           编译命令：g++ -std=c++20 -Wall 25-07-example9-error.cpp
//           该文件按设计无法编译，请勿修复（在 VS 上可编译并运行，输出 Sally says buzz）。
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name {};

public:
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }

    // Visual Studio 允许下面这种写法（非标准，GCC 会拒绝）
    virtual std::string_view speak() const = 0
    {
      return "buzz";
    }

    virtual ~Animal() = default;
};

class Dragonfly: public Animal
{
public:
    Dragonfly(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const override { return Animal::speak(); }
};

int main()
{
    Dragonfly dfly{ "Sally" };
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

    return 0;
}
