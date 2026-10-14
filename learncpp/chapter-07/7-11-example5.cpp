// 来源小节：7.11 Static local variables
// 示例说明：复用上一示例的 getInteger()（其静态状态无法重置）时出问题：
//           加、减各调两次，但第二次调用起提示语一律变成 "Enter another integer: "。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。需交互输入。
// 实际输出（注意重复出现的 "another" 提示）：
// Addition
// Enter an integer: 5
// Enter another integer: 9
// 5 + 9 = 14
// Subtraction
// Enter another integer: 12
// Enter another integer: 3
// 12 - 3 = 9

#include <iostream>

int getInteger()
{
	static bool s_isFirstCall{ true };

	if (s_isFirstCall)
	{
		std::cout << "Enter an integer: ";
		s_isFirstCall = false;
	}
	else
	{
		std::cout << "Enter another integer: ";
	}

	int i{};
	std::cin >> i;
	return i;
}

int main()
{
  std::cout << "Addition\n";

  int a{ getInteger() };
  int b{ getInteger() };

  std::cout << a << " + " << b << " = " << (a + b) << '\n';

  std::cout << "Subtraction\n";

  int c{ getInteger() };
  int d{ getInteger() };

  std::cout << c << " - " << d << " = " << (c - d) << '\n';

  return 0;
}
