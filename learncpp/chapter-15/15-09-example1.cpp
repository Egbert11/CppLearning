// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：把一个"类"设为友元类。Storage 用 friend class Display;
//           让 Display 的所有成员函数都能访问 Storage 的私有成员，
//           因此 Display::displayStorage() 能读取 Storage 的 m_nValue 与 m_dValue。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：
//   6.7 5
//   5 6.7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

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

	// 让 Display 类成为 Storage 的友元
	friend class Display;
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

	// 因为 Display 是 Storage 的友元，Display 的成员函数可以访问 Storage 的私有成员
	void displayStorage(const Storage& storage)
	{
		if (m_displayIntFirst)
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		else // 先显示 double
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
	}

	void setDisplayIntFirst(bool b)
	{
		m_displayIntFirst = b;
	}
};

int main()
{
	Storage storage { 5, 6.7 };
	Display display { false };

	display.displayStorage(storage);

	display.setDisplayIntFirst(true);
	display.displayStorage(storage);

	return 0;
}
