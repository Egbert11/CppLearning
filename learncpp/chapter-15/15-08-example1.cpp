// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：在 Accumulator 类里用 friend 声明把非成员函数 print()
//           设为友元；作为友元，print() 就能访问 Accumulator 的私有成员
//           m_value，尽管它并不是这个类的成员函数。
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

	// 这条 friend 声明让非成员函数 print() 成为 Accumulator 的友元
	friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator)
{
	// 因为 print() 是 Accumulator 的友元，
	// 它可以访问 Accumulator 的私有成员
	std::cout << accumulator.m_value;
}

int main()
{
	Accumulator acc{};
	acc.add(5); // 给累加器加 5
	print(acc); // 调用非成员函数 print()

	return 0;
}
