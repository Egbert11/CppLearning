// 来源小节：21.3 Overloading operators using normal functions
// 示例说明：多文件拆分——头文件中的 Cents 类，外加显式给出的 operator+ 原型；
//           其他翻译单元（main.cpp）必须看到这个原型才能用 cents1 + cents2。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/
// 说明：本节代码取自原文（逐字保留）。多文件示例，编译：
//       g++ -std=c++20 -Wall 21-03-example3/*.cpp

#ifndef CENTS_H
#define CENTS_H

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

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
Cents operator+(const Cents& c1, const Cents& c2);

#endif
