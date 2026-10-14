// 来源小节：21.14 Overloading operators and function templates
// 示例说明：为 Cents 增加 friend 的 operator<（比较私有成员 m_cents），max() 的实例化
//           就能编译并正确返回较大者。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/
// 说明：本节代码为按原文描述重建。
// 预期输出：10 is bigger

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents{ cents }
    {
    }

    friend bool operator< (const Cents& c1, const Cents& c2)
    {
        return c1.m_cents < c2.m_cents;
    }

    friend std::ostream& operator<< (std::ostream& ostr, const Cents& c)
    {
        ostr << c.m_cents;
        return ostr;
    }
};

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x < y) ? y : x;
}

int main()
{
    Cents nickel{ 5 };
    Cents dime{ 10 };

    Cents bigger{ max(nickel, dime) };
    std::cout << bigger << " is bigger\n";

    return 0;
}
