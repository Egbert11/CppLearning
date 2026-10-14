// ============================================================
// 来源小节：24.8 Hiding inherited functionality（原 Example 7 / 8）
// 示例说明：在派生类中把 getValue() 标记为 = delete，使它无法通过派生对象调用。
//           但基类版本依旧可达：既可以用 derived.Base::getValue() 直接调用，
//           也可以把派生对象转换为 Base& 后调用（注意转引用而非转值，避免拷贝）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
// 预期输出：
//   7
//   7
// 备注：本节代码为按原文描述重建。原示例中 derived.getValue() 属预期编译失败，这里注释保留。
// ============================================================
#include <iostream>

class Base
{
private:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    int getValue() const = delete; // mark this function as inaccessible
};

int main()
{
    Derived derived{ 7 };

    // std::cout << derived.getValue(); // error: getValue() has been deleted!

    // We can call the Base::getValue() function directly
    std::cout << derived.Base::getValue() << '\n';

    // Or we can upcast Derived to a Base reference and getValue() will resolve to Base::getValue()
    std::cout << static_cast<Base&>(derived).getValue() << '\n';

    return 0;
}
