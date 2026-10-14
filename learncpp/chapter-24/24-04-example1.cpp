// ============================================================
// 来源小节：24.4 Constructors and initialization of derived classes（原 Example 5 / 6）
// 示例说明：派生类构造函数在成员初始化列表中写 Base{ id }，显式选择基类的
//           Base(int) 构造函数来初始化继承来的 m_id；随后初始化自身的 m_cost。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
// 预期输出：
//   Id: 5
//   Cost: 1.3
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
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
public:
    double m_cost{};

    Derived(double cost = 0.0, int id = 0)
        : Base{ id }, // Call Base(int) constructor with value id!
          m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

int main()
{
    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor

    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}
