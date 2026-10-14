// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明：把枚举移入 Fruit 成为"嵌套类型"（member type）。因为类本身
//           已经提供了作用域，所以改用非限定枚举即可，类外通过
//           Fruit::apple 访问，类内直接用非限定名 cherry。
// 原文链接：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
// 预期输出：I am an apple
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Fruit
{
public:
	// 嵌套类型通常定义在类的最前面
	enum Type
	{
		apple,
		banana,
		cherry
	};

private:
	Type m_type{};
	int m_percentageEaten{ 0 };

public:
	Fruit(Type type)
		: m_type{ type }
	{
	}

	Type getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEaten; }

	// 类内可直接使用非限定枚举名
	bool isCherry() const { return m_type == cherry; }
};

int main()
{
	Fruit apple{ Fruit::apple }; // 类外必须写全限定名

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}
