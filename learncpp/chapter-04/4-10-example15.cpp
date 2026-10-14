// 来源小节：4.10 Introduction to if statements
// 示例说明：Quiz #3 解法——直接返回条件表达式，去掉多余的 if/else。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 原示例只是一个函数片段，这里补一个 main() 调用它。

#include <iostream>

bool isAllowedToTakeFunRide()
{
  std::cout << "How tall are you? (cm)\n";

  double height{};
  std::cin >> height;

  return height >= 140.0;
}

int main()
{
  if (isAllowedToTakeFunRide())
    std::cout << "Have fun!\n";
  else
    std::cout << "Sorry, you're too short.\n";

  return 0;
}
