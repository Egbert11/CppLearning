// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：类型推导限制——只有静态成员才能使用 auto 或 CTAD；非静态
//           数据成员不允许用 auto 或类模板实参推导（会出现歧义或反直觉
//           的结果）。此文件演示"非静态成员用 auto/CTAD"的编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期错误（不要修复）：
//   error: non-static data member declared with placeholder 'auto'
//   error: non-static data member declared with placeholder 'std::pair'
// 备注：这是演示预期编译失败的示例文件，请勿修复。
// ============================================================
#include <utility>

class Foo
{
private:
	auto m_x{ 5 };           // 错误：非静态数据成员不能用 auto
	std::pair m_v{ 1, 2.3 }; // 错误：非静态数据成员不能用 CTAD

public:
	Foo() = default;
};

int main()
{
	Foo foo{};
	(void)foo;

	return 0;
}
