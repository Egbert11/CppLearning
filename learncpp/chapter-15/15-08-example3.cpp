// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：对比"成员版本的比较函数"与"非成员版本的比较函数"。非成员版本
//           显式接收两个对象（两个参数并列），可读性更好；成员版本隐含接收
//           一个对象（this），另一个才显式传入。非成员版本同样能访问私有
//           成员，因为它被声明为友元。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/
// 预期输出：
//   0
//   0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Value
{
private:
	int m_value{};

public:
	explicit Value(int v)
		: m_value { v }
	{
	}

	bool isEqualToMember(const Value& v) const;
	friend bool isEqualToNonmember(const Value& v1, const Value& v2);
};

bool Value::isEqualToMember(const Value& v) const
{
	return m_value == v.m_value;
}

bool isEqualToNonmember(const Value& v1, const Value& v2)
{
	return v1.m_value == v2.m_value;
}

int main()
{
	Value v1 { 5 };
	Value v2 { 6 };

	std::cout << v1.isEqualToMember(v2) << '\n';
	std::cout << isEqualToNonmember(v1, v2) << '\n';

	return 0;
}
