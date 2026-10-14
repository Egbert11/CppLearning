// 来源小节：21.6 Overloading unary operators +, -, and !
// 示例说明：把一元 operator- 重载为成员函数——一元运算符没有参数，作用于 *this；
//           声明为 const 以便对 const 对象也能使用。返回类型是 Cents，因此 return -m_cents
//           会经 Cents(int) 构造函数隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-unary-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：A nickle of debt is worth -5 cents

#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents): m_cents{cents} {}

    // Overload -Cents as a member function
    Cents operator-() const;

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
Cents Cents::operator-() const
{
    return -m_cents; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}

int main()
{
    const Cents nickle{ 5 };
    std::cout << "A nickle of debt is worth " << (-nickle).getCents() << " cents\n";

    return 0;
}
