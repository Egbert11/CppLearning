// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：`0` 与 `NULL` 在重载解析中的歧义。`print(0)` 总是选整数版本；
//           `print(NULL)` 可能选任一版本或产生歧义错误（Visual Studio 选
//           print(int)；gcc 与 Clang 报歧义错误）；`print(nullptr)` 总是选
//           指针版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// !! -error：预期编译失败，请勿修复（在 gcc/Clang 上）。
//    预期错误：call of overloaded 'print(NULL)' is ambiguous（重载调用有歧义）。
//    原文在作者机器（Visual Studio）上可编译，输出为：
//      print(int*): non-null
//      print(int): 0
//      print(int): 0
//      print(int*): null
//    但在 gcc/Clang 上 print(NULL) 一行会因歧义而编译失败，故本文件为 -error。
// 备注：本节代码为按原文清单忠实重建（原 Example 5）。
// ============================================================
#include <iostream>
#include <cstddef> // for NULL

void print(int x) // this function accepts an integer
{
	std::cout << "print(int): " << x << '\n';
}

void print(int* ptr) // this function accepts an integer pointer
{
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

int main()
{
	int x{ 5 };
	int* ptr{ &x };

	print(ptr);  // always calls print(int*) because ptr has type int* (good)
	print(0);    // always calls print(int) because 0 is an integer literal (hopefully this is what we expected)

	print(NULL); // this statement could do any of the following:
	// call print(int) (Visual Studio does this)
	// call print(int*)
	// result in an ambiguous function call compilation error (gcc and Clang do this)

	print(nullptr); // always calls print(int*)

	return 0;
}
