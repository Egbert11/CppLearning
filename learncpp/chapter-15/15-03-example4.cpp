// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明：嵌套类（nested class）。嵌套类没有外层对象的 this 指针，
//           无法直接访问外层成员；但它是外层类的成员，可以访问外层类的
//           私有成员——办法是接收一个外层对象作参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
// 预期输出：John has id: 1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
public:
	using IDType = int;

	// 嵌套类 Printer：作为 Employee 的成员，可以访问 Employee 的私有成员
	class Printer
	{
	public:
		void print(const Employee& e) const
		{
			// 直接读取外层对象的私有成员（因为 Printer 是 Employee 的成员）
			std::cout << e.m_name << " has id: " << e.m_id << '\n';
		}
	};

private:
	std::string m_name{};
	IDType m_id{};
	double m_wage{};

public:
	Employee(std::string_view name, IDType id, double wage)
		: m_name{ name }
		, m_id{ id }
		, m_wage{ wage }
	{
	}
};

int main()
{
	Employee john{ "John", 1, 45000.0 };

	const Employee::Printer p{}; // 可以在类外使用嵌套类
	p.print(john);

	return 0;
}
