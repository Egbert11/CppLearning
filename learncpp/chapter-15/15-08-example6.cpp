// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：推荐做法——不用友元，改用公有访问函数 value()。print() 通过
//           类的公有接口取值，于是 Accumulator 的实现变化（例如私有成员
//           改名）不再需要修改 print()，从而降低耦合。这正是"能不用友元
//           就尽量不用"的理由。
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
	int value() const { return m_value; } // 公有访问函数
};

void print(const Accumulator& accumulator)
{
	std::cout << accumulator.value(); // 通过公有接口取值，不再需要友元
}

int main()
{
	Accumulator acc{};
	acc.add(5);
	print(acc);

	return 0;
}
