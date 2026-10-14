// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：与 example9 对比——静态成员允许 auto 与 CTAD，因此下面
//           写法完全合法，可正常编译运行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：5 与 1 2.3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <utility>

class Foo
{
public:
	static inline auto s_x{ 5 };             // ok：静态成员可用 auto
	static inline std::pair s_v{ 1, 2.3 };   // ok：静态成员可用 CTAD
};

int main()
{
	std::cout << Foo::s_x << '\n';
	std::cout << Foo::s_v.first << ' ' << Foo::s_v.second << '\n';

	return 0;
}
