// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明："嵌套之前"的写法——enum FruitType 定义在类外，
//           它能工作，但没有任何东西暗示它与 Fruit 搭配使用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
// 预期输出：I am an apple
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

enum class FruitType
{
	apple,
	banana,
	cherry
};

class Fruit
{
private:
	FruitType m_type{};
	int m_percentageEaten{ 0 };

public:
	Fruit(FruitType type)
		: m_type{ type }
	{
	}

	FruitType getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEaten; }
};

int main()
{
	Fruit apple{ FruitType::apple };

	if (apple.getType() == FruitType::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}
