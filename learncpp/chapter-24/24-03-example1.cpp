// ============================================================
// 来源小节：24.3 Order of construction of derived classes（原 Example 4）
// 示例说明：在 Base 与 Derived 的构造函数里打印踪迹，直观展示派生对象
//           构造时的顺序：先构造基类部分，再构造派生类部分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/
// 预期输出：
//   Instantiating Base
//   Base
//   Instantiating Derived
//   Base
//   Derived
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_id{};

    Base(int id = 0)
        : m_id{ id }
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
public:
    double m_cost{};

    Derived(double cost = 0.0)
        : m_cost{ cost }
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};

int main()
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    return 0;
}
