// ---------------------------------------------------------------------------
// 来源小节：25.11 Printing inherited classes using operator<<
// 原文链接：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
// 示例说明：问题所在——operator<< 不是（也不能是）虚函数，因此通过 Base& 输出时，
//           选中的是处理 Base 的那个重载，只打印 Base。
// 预期输出：Base
// 原文该例的 main() 为逐字提取；Base/Derived 定义取自原文 Example 3。
// ---------------------------------------------------------------------------

#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base"; }

	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }

	friend std::ostream& operator<<(std::ostream& out, const Derived& d)
	{
		out << "Derived";
		return out;
	}
};

// --- 原文示例片段 ---
int main()
{
    Derived d{};
    Base& bref{ d };
    std::cout << bref << '\n';

    return 0;
}
