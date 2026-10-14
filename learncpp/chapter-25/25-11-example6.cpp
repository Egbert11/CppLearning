// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：更灵活的方案——改为让虚成员函数 print(std::ostream&) 直接拿到流对象
//           完成打印，operator<< 只负责转发。这样能打印自身也有 operator<< 的成员
//           （例如这里的 Employee）。
// 预期输出：
//   Base
//   Derived: Employee(Jim, 4)
//   Derived: Employee(Jim, 4)
// 代码为原文逐字提取（补上 <string> 以便编译）。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>

class Base
{
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		// Delegate printing responsibility for printing to virtual member function print()
		return b.print(out);
	}

	// We'll rely on member function print() to do the actual printing
	// Because print() is a normal member function, it can be virtualized
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

// Some class or struct with an overloaded operator<<
struct Employee
{
	std::string name{};
	int id{};

	friend std::ostream& operator<<(std::ostream& out, const Employee& e)
	{
		out << "Employee(" << e.name << ", " << e.id << ")";
		return out;
	}
};

class Derived : public Base
{
private:
	Employee m_e{}; // Derived now has an Employee member

public:
	Derived(const Employee& e)
		: m_e{ e }
	{
	}

	// Here's our override print() function to handle the Derived case
	std::ostream& print(std::ostream& out) const override
	{
		out << "Derived: ";

		// Print the Employee member using the stream object
		out << m_e;

		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{ Employee{"Jim", 4}};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref{ d };
	std::cout << bref << '\n';

	return 0;
}
