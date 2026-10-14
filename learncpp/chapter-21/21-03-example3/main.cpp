// 来源小节：21.3 Overloading operators using normal functions
// 示例说明：main 使用 Cents 和 cents1 + cents2；若 Cents.h 里没有 operator+ 的原型，
//           这里会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：I have 14 cents.

#include "Cents.h"
#include <iostream>

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 }; // without the prototype in Cents.h, this would fail to compile
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}
