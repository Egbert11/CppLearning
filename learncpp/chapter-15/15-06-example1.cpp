// ============================================================
// 来源小节：15.6 Static member variables
// 示例说明：回顾静态存储期——函数内的 static 局部变量在程序启动时创建、
//           在程序结束时销毁，离开作用域后仍保留其值。三次调用返回 1、2、3。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-variables/
// 预期输出：1 2 3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int generateID()
{
	static int s_id{ 0 }; // 静态局部变量
	return ++s_id;
}

int main()
{
	std::cout << generateID() << '\n';
	std::cout << generateID() << '\n';
	std::cout << generateID() << '\n';

	return 0;
}
