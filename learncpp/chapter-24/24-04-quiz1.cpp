// ============================================================
// 来源小节：24.4 Constructors and initialization of derived classes（本节测验·解答）
// 示例说明：创建 Fruit 基类（name + color）。Apple 继承 Fruit 并增加私有 double
//           成员 m_fiber；Banana 继承 Fruit、无额外成员。为两者分别重载
//           operator<<。main 用 const 对象，因此访问器须是 const 成员函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
// 预期输出：
//   Apple(Red delicious, red, 4.2)
//   Banana(Cavendish, yellow)
// 备注：本节代码为按原文描述重建（原 Example 12 / 13，即测验解答）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string_view name, std::string_view color)
        : m_name{ name }, m_color{ color }
    {
    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
private:
    double m_fiber;

public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit{ name, color }, m_fiber{ fiber }
    {
    }

    double getFiber() const { return m_fiber; }
};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')';
    return out;
}

class Banana : public Fruit
{
public:
    Banana(std::string_view name, std::string_view color)
        : Fruit{ name, color }
    {
    }
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
    return out;
}

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}
