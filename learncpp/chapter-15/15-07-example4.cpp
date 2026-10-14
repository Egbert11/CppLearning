// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：把访问函数声明为 static，就能直接用"类名 + :: "调用它，
//           完全不需要创建对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Something
{
private:
	static inline int s_value { 1 };

public:
	static int getValue() { return s_value; } // 静态成员函数
};

int main()
{
	std::cout << Something::getValue() << '\n'; // 无需对象
	return 0;
}
