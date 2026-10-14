// ============================================================
// 来源小节：15.10 Ref qualifiers
// 示例说明：用 ref-qualifier 解决上面的两难：给 getter 提供两个重载——
//           const & 版本匹配左值隐式对象（按引用返回，高效）；
//           const && 版本匹配右值隐式对象（按值返回，安全）。
//           左值对象走引用、右值对象走拷贝，"对象是左值时做高效的事、
//           是右值时做安全的事"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ref-qualifiers/
// 预期输出：
//   Joe
//   Frank
// 备注：本节代码为按原文描述重建。（原文 Example 2 只给出了两条声明片段，
//        已并入本示例的两个重载中。）
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
	std::string m_name{};

public:
	Employee(std::string_view name): m_name { name } {}

	//  & 限定：只匹配左值隐式对象，按引用返回
	const std::string& getName() const &  { return m_name; }
	// && 限定：只匹配右值隐式对象，按值返回
	std::string        getName() const && { return m_name; }
};

// createEmployee() 按值返回 Employee（因此返回值是右值）
Employee createEmployee(std::string_view name)
{
	Employee e { name };
	return e;
}

int main()
{
	Employee joe { "Joe" };
	std::cout << joe.getName() << '\n'; // joe 是左值，调用 std::string& getName() &（返回引用）

	std::cout << createEmployee("Frank").getName() << '\n'; // Frank 是右值，调用 std::string getName() &&（产生一份拷贝）

	return 0;
}
