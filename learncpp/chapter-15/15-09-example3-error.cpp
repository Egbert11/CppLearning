// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：按提示把 Display 的定义移到 Storage 之前（失败方式变了）。
//           displayStorage 的参数是 const Storage&，但此时编译器还不知道
//           Storage 是什么（它尚未定义、也没有前向声明）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期错误（不要修复）：
//   error: 'Storage' does not name a type
//          （此处 Storage 既未定义也未前向声明）
// 备注：这是演示预期编译失败的示例文件，请勿修复。
// ============================================================
#include <iostream>

class Display
{
private:
	bool m_displayIntFirst {};

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{
	}

	void displayStorage(const Storage& storage) // 错误：此时还不知道 Storage 是什么
	{
		if (m_displayIntFirst)
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		else
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
	}
};

class Storage
{
private:
	int m_nValue {};
	double m_dValue {};

public:
	Storage(int nValue, double dValue)
		: m_nValue { nValue }, m_dValue { dValue }
	{
	}

	friend void Display::displayStorage(const Storage& storage); // 现在没问题了
};

int main()
{
	Storage storage { 5, 6.7 };
	Display display { false };
	display.displayStorage(storage);

	return 0;
}
