// 来源小节：4.9 Boolean values
// 示例说明：用整数做花括号初始化：0 和 1 合法，2 属于被禁止的窄化转换，会编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 注意：本示例**故意演示编译错误**——bool bNo { 2 }; 会导致
//       "narrowing conversion of '2' from 'int' to 'bool'" 编译错误，无法通过编译。

#include <iostream>

int main()
{
	bool bFalse { 0 }; // okay: initialized to false
	bool bTrue  { 1 }; // okay: initialized to true
	bool bNo    { 2 }; // error: narrowing conversions disallowed

	std::cout << bFalse << bTrue << bNo << '\n';

	return 0;
}
