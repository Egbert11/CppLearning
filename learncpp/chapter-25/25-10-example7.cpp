// ---------------------------------------------------------------------------
// 来源小节：25.10 Dynamic casting
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-casting/
// 示例说明：对引用做 dynamic_cast 时，转换失败会抛出 std::bad_cast 异常
//           （因为 C++ 没有「空引用」）。这里捕获该异常并打印提示。
// 预期输出：Bad cast caught
// 代码为按原文描述重建的演示（原文正文描述了该行为，未给出该独立代码清单）。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <string_view>
#include <typeinfo> // for std::bad_cast

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
public:
    Derived(int value)
        : Base{ value }
    {
    }
};

int main()
{
    Base base{ 2 }; // 一个纯 Base 对象
    Base& b{ base };

    try
    {
        // 失败：会抛出 std::bad_cast
        Derived& d{ dynamic_cast<Derived&>(b) };
        (void)d;
    }
    catch (const std::bad_cast&)
    {
        std::cout << "Bad cast caught\n";
    }

    return 0;
}
