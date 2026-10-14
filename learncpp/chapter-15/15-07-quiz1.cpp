// ============================================================
// 来源小节：15.7 Static member functions
// 示例说明：小测验——把 8.15 里提供随机数的 Random 命名空间改写成一个
//           全静态成员的类：把 generate() 与 mt 变成私有静态成员，把 get()
//           变成公有静态函数。这样既保持了"整个程序只有一份"的随机数
//           引擎，又无需创建任何对象即可调用 Random::get()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-member-functions/
// 预期输出：10 个 1..6 之间的随机整数（每次运行不同），一行显示。
// 备注：本节代码为按原文描述重建。原题从 8.15 的 Random.h 改写而来，
//        此处内联为一个自包含程序。因结果随机，无法给出固定输出。
// ============================================================
#include <chrono>
#include <iostream>
#include <random>

class Random
{
private:
	static std::mt19937 generate()
	{
		std::random_device rd{};

		// 用系统时钟当前时间 + 7 个随机数作为种子
		std::seed_seq ss {
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd()
		};

		return std::mt19937{ ss };
	}

	static inline std::mt19937 mt{ generate() }; // 属于类的一份引擎实例

public:
	static int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
};

int main()
{
	for (int count{ 0 }; count < 10; ++count)
		std::cout << Random::get(1, 6) << ' ';

	std::cout << '\n';
	return 0;
}
