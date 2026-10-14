// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：静态成员函数可以在类外定义。类内保留声明，类外的定义
//           不再写 static 关键字。这里用一个 ID 生成器演示每次调用
//           返回递增的唯一编号。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：
//   The next ID is: 1
//   The next ID is: 2
//   The next ID is: 3
//   The next ID is: 4
//   The next ID is: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class IDGenerator
{
private:
	static inline int s_nextID { 1 };

public:
	static int getNextID(); // 类内声明
};

// 类外定义：注意这里不写 static 关键字
int IDGenerator::getNextID() { return s_nextID++; }

int main()
{
	for (int count { 0 }; count < 5; ++count)
		std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

	return 0;
}
