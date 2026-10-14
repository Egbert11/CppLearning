// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：Frankenobject——拷贝赋值运算符不是虚函数，`Base& b{ d2 }; b = d1;`
//           只把 d1 的 Base 部分拷贝进 d2 的 Base 子对象，于是 d2 变成由多个
//           对象的部分拼成的「缝合怪」。
// 命名后缀：-broken（坏实践/易错的写法，编译通过但语义错误）。
// 预期输出：无（程序本身不打印；此处演示的是赋值语义问题）。
// 原文该例的 main() 为逐字提取；Base/Derived 定义取自原文同一小节前例。
// ---------------------------------------------------------------------------

#include <iostream>
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

    virtual std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

   std::string_view getName() const override { return "Derived"; }
};

int main()
{
    Derived d1{ 5 };
    Derived d2{ 6 };
    Base& b{ d2 };

    b = d1; // this line is problematic

    return 0;
}
