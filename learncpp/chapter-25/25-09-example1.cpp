// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：基类引用/指针指向派生类对象时只能看到基类子对象，但派生部分仍存在，
//           虚函数依旧派发到最派生的重写版本，因此三行都打印 Derived。
// 预期输出：
//   derived is a Derived and has value 5
//   ref is a Derived and has value 5
//   ptr is a Derived and has value 5
// 代码为原文逐字提取。
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
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base& ref{ derived };
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base* ptr{ &derived };
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    return 0;
}
