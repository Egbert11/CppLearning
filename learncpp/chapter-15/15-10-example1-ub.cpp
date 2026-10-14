// ============================================================
// 来源小节：15.10 Ref qualifiers
// 示例说明：当访问函数返回"数据成员的引用"，而隐式对象是右值（临时对象）
//           时，把该引用保存下来继续使用会产生悬垂引用（dangling reference）。
//           情况 1（同一表达式内立即使用）是安全的；情况 2（保存引用稍后
//           使用）是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ref-qualifiers/
// 预期输出：本程序可编译运行，但情况 2 为 UB，其输出依实现而定
//           （本例中通常先正确打印一次 Frank，随后 ref 悬垂，
//             后续打印 Garbo 是未定义行为）。
// 备注：本节代码为按原文描述重建。文件后缀 -ub 表示这里演示未定义行为。
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
	const std::string& getName() const { return m_name; } // 按 const 引用返回
};

// createEmployee() 按值返回 Employee（因此返回值是右值）
Employee createEmployee(std::string_view name)
{
	Employee e { name };
	return e;
}

int main()
{
	// 情况 1：安全——在同一个表达式里使用"右值类对象的成员引用"
	std::cout << createEmployee("Frank").getName() << '\n';

	// 情况 2：危险——把"右值类对象的成员引用"保存下来稍后使用
	const std::string& ref { createEmployee("Garbo").getName() }; // createEmployee() 的返回值销毁后，ref 悬垂
	std::cout << ref << '\n'; // 未定义行为

	return 0;
}
