// 来源小节：21.2 Overloading the arithmetic operators using friend functions
// 示例说明：MinMax 类（记录已见最小值与最大值），用三个 operator+ 重载分别支持
//           MinMax+MinMax、MinMax+int、int+MinMax；链式相加 m1 + m2 + 5 + 8 + m3 + 16
//           从左到右逐次求值，operator+(int, MinMax) 只是转调 operator+(MinMax, int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：Result: (3, 16)

#include <iostream>

class MinMax
{
private:
	int m_min {}; // The min value seen so far
	int m_max {}; // The max value seen so far

public:
	MinMax(int min, int max)
		: m_min { min }, m_max { max }
	{ }

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax& m1, const MinMax& m2);
	friend MinMax operator+(const MinMax& m, int value);
	friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
	// Get the minimum value seen in m1 and m2
	int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

	// Get the maximum value seen in m1 and m2
	int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

	return MinMax { min, max };
}

MinMax operator+(const MinMax& m, int value)
{
	// Get the minimum value seen in m and value
	int min{ m.m_min < value ? m.m_min : value };

	// Get the maximum value seen in m and value
	int max{ m.m_max > value ? m.m_max : value };

	return MinMax { min, max };
}

MinMax operator+(int value, const MinMax& m)
{
	// calls operator+(MinMax, int)
	return m + value;
}

int main()
{
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
}
