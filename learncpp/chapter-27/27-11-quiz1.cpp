// 来源小节：27.x Chapter 27 summary and quiz
// 示例说明：章节测验第 1 题解答——Fraction 类，构造函数在分母为 0 时抛出 std::runtime_error；
//           main 中读入两个整数，合法则打印分数，非法则捕获 std::exception 并报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-27-summary-and-quiz/
// 预期运行（输入 5 和 0）：
//   Enter the numerator: 5
//   Enter the denominator: 0
//   Invalid denominator

#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <exception> // for std::exception

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }
		, m_denominator{ denominator }
	{
		if (m_denominator == 0)
			throw std::runtime_error("Invalid denominator");
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	std::cout << "Enter the numerator: ";
	int numerator{};
	std::cin >> numerator;

	std::cout << "Enter the denominator: ";
	int denominator{};
	std::cin >> denominator;

	try
	{
		Fraction f{ numerator, denominator };
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
