// 来源小节：21.3 Overloading operators using normal functions
// 示例说明：回顾——用友元函数重载 operator+，函数体可以借助友元身份直接访问 m_cents。
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

  // add Cents + Cents using a friend function
  friend Cents operator+(const Cents& c1, const Cents& c2);

  int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
  // use the Cents constructor and operator+(int, int)
  // we can access m_cents directly because this is a friend function
  return { c1.m_cents + c2.m_cents };
}

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 };
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}
