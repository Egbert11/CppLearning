// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：演示"直接访问私有成员"带来的耦合问题（原文 Example 5 用批注
//           说明）。print() 直接读 accumulator.m_value；一旦把私有成员改名，
//           类本身、add()、以及这个友元 print() 都得跟着改。程序本身可编译
//           可运行，此处用注释标出这些"会随实现变化而改动"的位置。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/
// 预期输出：5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Accumulator
{
private:
	int m_value { 0 }; // 若把 m_value 改名，下面所有使用它的地方都要改

public:
	void add(int value) { m_value += value; } // 直接依赖 m_value 的名字

	friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator)
{
	// 友元直接访问私有成员：实现一旦变化（例如 m_value 改名），
	// 这里就必须同步修改 —— 这正是"直接访问很脆弱"的地方。
	std::cout << accumulator.m_value;
}

int main()
{
	Accumulator acc{};
	acc.add(5);
	print(acc);

	return 0;
}
