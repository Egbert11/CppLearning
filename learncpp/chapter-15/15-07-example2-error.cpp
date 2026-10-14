// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：把静态成员变量改为 private 后，在类外直接用"类名 + :: "
//           访问它就会编译失败——私有成员不能在类外直接访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期错误（不要修复）：
//   error: 'int Something::s_value' is private within this context
//   （s_value 是私有静态成员，类外不能直接访问）
// 备注：这是演示预期编译失败的示例文件，请勿修复。
//        这也正是需要"访问函数"的原因。
// ============================================================
#include <iostream>

class Something
{
private:
	static inline int s_value { 1 };
};

int main()
{
	std::cout << Something::s_value << '\n'; // 错误：s_value 是 private
	return 0;
}
