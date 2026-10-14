// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 8）
// 示例说明：函数模板本身不能被偏特化，但可以让参数类型成为一个"部分特化类
//           类型"——这里 print 的重载把类型固定为 char、长度仍为模板参数，
//           一个函数即可服务任意长度的 char 数组。这不是函数偏特化，而是
//           一个以部分特化类为参数的重载函数模板。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出：
//   Hello, world! Hello, mom!
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <algorithm>
#include <iostream>
#include <string_view>

template <typename T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	const T& operator[](int index) const { return m_array[index]; }
	T& operator[](int index) { return m_array[index]; }
};

template <typename T, int size>
void print(const StaticArray<T, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// overload of print() function for partially specialized StaticArray<char, size>
template <int size>
void print(const StaticArray<char, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
}

int main()
{
	// Declare an char array of size 14
	StaticArray<char, 14> char14{};

	// Copy some data into it
	constexpr std::string_view hello14{ "Hello, world!" };
	std::copy_n(hello14.begin(), hello14.size(), char14.getArray());

	// Print the array
	print(char14);

	std::cout << ' ';

	// Now declare an char array of size 12
	StaticArray<char, 12> char12{};

	// Copy some data into it
	constexpr std::string_view hello12{ "Hello, mom!" };
	std::copy_n(hello12.begin(), hello12.size(), char12.getArray());

	// Print the array
	print(char12);

	return 0;
}
