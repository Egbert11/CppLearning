// ============================================================
// 来源小节：15.3 Nested types (member types)
// 示例说明：类里也可以嵌套类型别名（using）。类内用非限定名 IDType，
//           类外用全限定名 Employee::IDType。
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
	using IDType = int; // 嵌套类型别名（也可以写成 typedef int IDType;）

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

	const std::string& getName() const { return m_name; }
	IDType getId() const { return m_id; } // 类内可直接用非限定名 IDType
};

int main()
{
	Employee john{ "John", 1, 45000.0 };
	std::cout << john.getName() << " has id: " << john.getId() << '\n';

	Employee::IDType id{ john.getId() }; // 类外必须用全限定名 Employee::IDType
	std::cout << "id copy: " << id << '\n';

	return 0;
}
