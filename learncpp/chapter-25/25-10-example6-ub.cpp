// ---------------------------------------------------------------------------
// 来源小节：25.10 Dynamic casting
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-casting/
// 示例说明：dynamic_cast 向下转换失败时返回空指针，若不检查就直接解引用，
//           即为未定义行为（通常导致崩溃）。本文件演示「失败且不检查」的写法。
// 命名后缀：-ub（未定义行为演示，可编译；运行结果依实现而定，很可能崩溃）。
// 预期输出（UB）：无保证；在多数平台上会段错误崩溃。
// 教程规则：始终检查 dynamic_cast 的结果是否为空指针。
// 代码为按原文规则重建的演示（原文正文描述了该失败场景，未给出独立代码清单）。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual ~Base() = default;
};

class Derived : public Base
{
protected:
    std::string m_name{};

public:
    Derived(int value, std::string_view name)
        : Base{ value }, m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

Base* getObject(bool returnDerived)
{
    if (returnDerived)
        return new Derived{ 1, "Apple" };
    else
        return new Base{ 2 };
}

int main()
{
    Base* b{ getObject(false) }; // 这实际上是 Base 对象

    Derived* d{ dynamic_cast<Derived*>(b) }; // 转换失败，d 为 nullptr

    // 未检查 d 就用它 -> 未定义行为（解引用空指针）
    std::cout << "The name of the Derived is: " << d->getName() << '\n';

    delete b;

    return 0;
}
