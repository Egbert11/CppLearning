// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：单文件里让"单个成员函数"成为友元的正确写法。完整顺序为：
//           1) 前向声明 class Storage;
//           2) 在 Display 中声明 displayStorage（不在此处定义，因为 Storage 不完整）
//           3) 完整定义 Storage，并在其中 friend void Display::displayStorage(...)
//           4) 在 Storage 完整定义之后，才定义 Display::displayStorage
//           要点：前向声明足以支持"引用"，但访问成员需要完整定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：6.7 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Storage; // Storage 的前向声明

class Display
{
private:
	bool m_displayIntFirst {};

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{
	}

	void displayStorage(const Storage& storage); // 参数用到 Storage 的引用，前向声明已足够
};

class Storage // Storage 的完整定义
{
private:
	int m_nValue {};
	double m_dValue {};

public:
	Storage(int nValue, double dValue)
		: m_nValue { nValue }, m_dValue { dValue }
	{
	}

	// 把 Display::displayStorage 设为 Storage 的友元成员函数
	// 需要先看到 Display 的完整定义（因为 displayStorage 是 Display 的成员）
	friend void Display::displayStorage(const Storage& storage);
};

// 现在可以定义 Display::displayStorage 了
// 需要在 Storage 完整定义之后，因为访问了 storage 的成员
void Display::displayStorage(const Storage& storage)
{
	if (m_displayIntFirst)
		std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
	else
		std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

int main()
{
	Storage storage { 5, 6.7 };
	Display display { false };
	display.displayStorage(storage);

	return 0;
}
