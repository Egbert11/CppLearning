// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：当初始化需要"执行代码"时，用一个返回对象的静态函数来生成
//           初始值：static inline Chars s_mychars { generate() };，
//           把 generate() 返回的对象拷贝进去。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：i
// 备注：本节代码为按原文描述重建。私有的静态 generate() 不对外暴露。
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
private:
	static Chars generate()
	{
		Chars c{}; // 创建一个对象
		c.first  = 'a';
		c.second = 'e';
		c.third  = 'i';
		c.fourth = 'o';
		c.fifth  = 'u';
		return c;
	}

public:
	static inline Chars s_mychars { generate() };
};

int main()
{
	std::cout << MyClass::s_mychars.third << '\n'; // 打印 'i'
	return 0;
}
