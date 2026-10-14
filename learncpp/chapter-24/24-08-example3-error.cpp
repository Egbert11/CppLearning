// ============================================================
// 来源小节：24.8 Hiding inherited functionality（原 Example 6）
// 示例说明：using 声明会改变【该名字的所有重载】的访问级别。Base 有两个 getValue
//           重载，Derived 用 using Base::getValue; 把它放进 private，于是两次调用
//           都编译失败——不能只改变其中一个重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
// 预期错误（g++ 报错信息类似）：
//   error: 'int Base::getValue() const' is private within this context
//   error: 'int Base::getValue(int) const' is private within this context
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_value{};

    int getValue() const { return m_value; }
    int getValue(int) const { return m_value; }
};

class Derived : public Base
{
private:
    using Base::getValue; // make ALL getValue functions private

public:
    Derived(int value) : Base{ value }
    {
    }
};

int main()
{
    Derived derived{ 7 };
    std::cout << derived.getValue();  // ERROR: getValue() is private in Derived
    std::cout << derived.getValue(5); // ERROR: getValue(int) is private in Derived

    return 0;
}
