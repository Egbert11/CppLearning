// 来源小节：21.3 Overloading operators using normal functions
// 示例说明：operator+ 的定义（普通函数，非成员非友元），通过 getCents() 求和。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/
// 说明：本节代码取自原文（逐字保留）。

#include "Cents.h"

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return { c1.getCents() + c2.getCents() };
}
