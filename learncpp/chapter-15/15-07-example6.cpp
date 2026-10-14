// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：当静态成员可以直接初始化时，就在定义处直接初始化它
//           （即使它是 private 也允许）。这里用花括号直接填充一个字符结构。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：i
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

struct Chars
{
	char first{};
	char second{};
	char third{};
	char fourth{};
	char fifth{};
};

class MyClass
{
public:
	static inline Chars s_mychars { 'a', 'e', 'i', 'o', 'u' };
};

int main()
{
	std::cout << MyClass::s_mychars.third << '\n'; // 打印 'i'
	return 0;
}
