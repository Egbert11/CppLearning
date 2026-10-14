// 来源小节：4.10 Introduction to if statements
// 示例说明：Quiz #3——原始的游乐设施程序（判断身高是否达到 140cm）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

#include <iostream>

bool isAllowedToTakeFunRide()
{
  std::cout << "How tall are you? (cm)\n";

  double height{};
  std::cin >> height;

  if (height >= 140.0)
    return true;
  else
    return false;
}

int main()
{
  if (isAllowedToTakeFunRide())
    std::cout << "Have fun!\n";
  else
    std::cout << "Sorry, you're too short.\n";

  return 0;
}
