// ============================================================
// 来源小节：24.4 Constructors and initialization of derived classes（原 Example 3）
// 示例说明：演示【预期编译失败】的错误写法——派生类构造函数试图在自己的成员
//           初始化列表里初始化继承来的成员 m_id{ id }。规则：一个成员只能由
//           拥有它的那个类的构造函数初始化，所以这里派生类不能初始化 Base 的
//           m_id。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
// 预期错误（g++ 报错信息类似）：
//   error: class 'Derived' does not have any field named 'm_id'
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_id{};

    Base(int id = 0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
public:
    double m_cost{};

    Derived(double cost = 0.0, int id = 0)
        : m_id{ id }, // not allowed: Derived can't initialize inherited member Base::m_id
          m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

int main()
{
    Derived derived{ 1.3, 5 };

    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}
