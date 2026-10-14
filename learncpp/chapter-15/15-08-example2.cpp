// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：友元函数也可以在类体内部定义（前面加 friend）。这并不会让它
//           变成成员函数——它仍然是"定义在类内的非成员函数"，与定义在
//           类外完全等价。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/
// 预期输出：5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Accumulator
{
private:
	int m_value { 0 };

public:
	void add(int value) { m_value += value; }

	// 在类内定义友元函数 print()；它仍是非成员函数
	friend void print(const Accumulator& accumulator)
	{
		std::cout << accumulator.m_value;
	}
};

int main()
{
	Accumulator acc{};
	acc.add(5);
	print(acc);

	return 0;
}
