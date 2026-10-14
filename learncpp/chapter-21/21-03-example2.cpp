// 来源小节：21.3 Overloading operators using normal functions
// 示例说明：把 operator+ 写成普通（非成员、非友元）函数——通过公开访问器 getCents()
//           取值，因此不需要友元身份；此时必须在头文件里显式给出原型（多文件时见 example3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：I have 14 cents.

#include <iostream>

class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
    : m_cents{ cents }
  {}

  int getCents() const { return m_cents; }
};

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return Cents{ c1.getCents() + c2.getCents() };
}

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 };
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}
