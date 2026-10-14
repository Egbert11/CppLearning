// ============================================================
// 来源小节：13.9 Default member initialization
// 示例说明：所有成员均有默认值时，用四种方式（无列表 / 空列表 / 部分 / 全部）构造对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-member-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Fraction
{
	int numerator { }; // we should use { 0 } here, but for the sake of example we'll use value initialization instead
	int denominator { 1 };
};

int main()
{
	// --- 原文示例片段（原 Example 5）---
	Fraction f1;          // f1.numerator value initialized to 0, f1.denominator defaulted to 1
	Fraction f2 {};       // f2.numerator value initialized to 0, f2.denominator defaulted to 1
	Fraction f3 { 6 };    // f3.numerator initialized to 6, f3.denominator defaulted to 1
	Fraction f4 { 5, 8 }; // f4.numerator initialized to 5, f4.denominator initialized to 8

	std::cout << f1.numerator << '/' << f1.denominator << '\n';
	std::cout << f2.numerator << '/' << f2.denominator << '\n';
	std::cout << f3.numerator << '/' << f3.denominator << '\n';
	std::cout << f4.numerator << '/' << f4.denominator << '\n';

	return 0;
}

// 预期输出：
// 0/1
// 0/1
// 6/1
// 5/8
