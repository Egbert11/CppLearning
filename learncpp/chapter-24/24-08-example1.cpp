// ============================================================
// 来源小节：24.8 Hiding inherited functionality（原 Example 2 / 3）
// 示例说明：Base::printValue() 是 protected。派生类在 public 区写
//           using Base::printValue;（注意没有括号）把它提升为 public，
//           于是外部代码可以直接调用 derived.printValue()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
// 预期输出：
//   7
// 备注：本节代码为按原文描述重建。
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

protected:
    void printValue() const { std::cout << m_value; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

int main()
{
    Derived derived{ 7 };

    // printValue is public in Derived, so this is okay
    derived.printValue(); // prints 7
    std::cout << '\n';

    return 0;
}
