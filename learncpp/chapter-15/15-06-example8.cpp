// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：静态成员的实用场景——唯一 ID 生成器。共享计数器让每个对象
//           拿到不同的 ID，按创建顺序递增，调试数据数组时很有用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：1 2 3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Something
{
private:
	static inline int s_idGenerator{ 1 }; // C++17
	int m_id{};

public:
	Something()
		: m_id{ s_idGenerator++ } // 从生成器取出下一个 ID
	{
	}

	int getID() const { return m_id; }
};

int main()
{
	Something first{};
	Something second{};
	Something third{};

	std::cout << first.getID() << '\n';
	std::cout << second.getID() << '\n';
	std::cout << third.getID() << '\n';

	return 0;
}
