// ============================================================
// 来源小节：15.5 Class templates with member functions
// 文件说明：Quiz #2 的原理演示——只有 const 成员函数才能在 const 对象上
//           调用，因为非 const 成员函数可能修改对象。原文 Quiz #2 以文字
//           作答（无代码），此文件为据此原理重建的示意示例。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/
// 预期错误（不要修复）：
//   error: passing 'const Triad<int, int, int>' as 'this' argument discards
//          qualifiers [-fpermissive]
// 备注：这是演示预期编译失败的示例文件，请勿修复。
// ============================================================
template <typename T, typename U, typename V>
class Triad
{
private:
	T m_first{};
	U m_second{};
	V m_third{};

public:
	Triad(const T& first, const U& second, const V& third)
		: m_first{ first }
		, m_second{ second }
		, m_third{ third }
	{
	}

	// 非 const 访问函数：不能在 const 对象上调用
	T& first() { return m_first; }
};

int main()
{
	const Triad<int, int, int> t1{ 1, 2, 3 };
	t1.first(); // 错误：在 const 对象上调用非 const 成员函数

	return 0;
}
