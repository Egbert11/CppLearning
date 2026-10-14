// ============================================================
// 来源小节：15.10 Ref qualifiers
// 示例说明：（进阶读者）当隐式对象是"非 const 右值"时，它在表达式结束后
//           即将销毁，因此右值重载可以直接 std::move(m_name) 把成员移出，
//           避免一次昂贵拷贝。此处的 && 重载不再带 const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ref-qualifiers/
// 预期输出：
//   Joe
//   Frank
// 备注：本节代码为按原文描述重建。原文指出：因为 const 右值并不常见，
//        这个 std::move 版本通常可以替代上面的 const && 版本。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <utility> // std::move

class Employee
{
private:
	std::string m_name{};

public:
	Employee(std::string_view name): m_name { name } {}

	const std::string& getName() const & { return m_name; } // 左值：按引用返回

	// 隐式对象是非 const 右值时，尝试把 m_name 移动出去
	std::string getName() && { return std::move(m_name); }
};

Employee createEmployee(std::string_view name)
{
	Employee e { name };
	return e;
}

int main()
{
	Employee joe { "Joe" };
	std::cout << joe.getName() << '\n';

	std::cout << createEmployee("Frank").getName() << '\n';

	return 0;
}
