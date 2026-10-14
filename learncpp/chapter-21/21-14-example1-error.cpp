// 来源小节：21.14 Overloading operators and function templates
// 示例说明：函数模板 max() 的函数体里用到了 x < y。当传入自定义类型 Cents 时，编译器没有
//           比较 Cents 的办法，于是实例化出来的函数无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/
// 说明：本节代码为按原文描述重建。此文件预期编译失败（勿修复！）：
//       error: no match for 'operator<' (operand types are 'const Cents' and 'const Cents')
//       规则：想对某类型使用 max()，就要为它重载 operator<（见 21-14-example2.cpp）。

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
