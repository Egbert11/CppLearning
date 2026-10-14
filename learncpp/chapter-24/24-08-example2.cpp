// ============================================================
// 来源小节：24.8 Hiding inherited functionality（原 Example 4）
// 示例说明：把公有成员 m_value 在派生类中通过 using Base::m_value; 变私有，
//           从派生对象直接访问会编译失败；但 m_value 在 Base 中仍是 public，
//           转换为 Base& 后即可绕过封装直接访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
// 预期输出：
//   7
//   7
// 备注：本节代码为按原文描述重建。原示例中 directly 访问 derived.m_value 属预期
//       编译失败，这里改为注释保留。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_value{};
};

class Derived : public Base
{
private:
    using Base::m_value;

public:
    Derived(int value) : Base{ value }
    {
    }
};

int main()
{
    Derived derived{ 7 };
    // std::cout << derived.m_value; // error: m_value is private in Derived

    Base& base{ derived };
    std::cout << base.m_value << '\n'; // okay: m_value is public in Base

    return 0;
}
