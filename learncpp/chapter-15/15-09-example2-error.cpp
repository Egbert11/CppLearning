// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：把"单个成员函数"设为友元的第一次尝试（失败）。Storage 定义在
//           Display 之前，并在类内写 friend void Display::displayStorage(...);
//           但要把某个类的成员函数设为友元，编译器必须已经看到那个类的
//           "完整定义"，而此处只有 Display 的前向声明。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期错误（不要修复）：
//   error: invalid use of incomplete type 'class Display'
//          （Storage 尚未看到 Display 的完整定义，无法引用 Display::displayStorage）
// 备注：这是演示预期编译失败的示例文件，请勿修复。
// ============================================================
#include <iostream>

class Display; // Display 的前向声明

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

	// 把 Display::displayStorage 设为 Storage 的友元成员函数
	// 需要先看到 Display 的完整定义（因为 displayStorage 是 Display 的成员）
	friend void Display::displayStorage(const Storage& storage); // 错误：Storage 尚未看到 Display 的完整定义
};

class Display
{
private:
	bool m_displayIntFirst {};

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{
	}

	void displayStorage(const Storage& storage)
	{
		if (m_displayIntFirst)
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		else
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
	}
};

int main()
{
	Storage storage { 5, 6.7 };
	Display display { false };
	display.displayStorage(storage);

	return 0;
}
