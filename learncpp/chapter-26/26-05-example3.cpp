// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 5）
// 示例说明：为恰好 StaticArray<char, 14> 做一个函数模板全特化。能正常工作，
//           但换个长度（如 12）就不再匹配——说明它不够通用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出：
//   Hello, world!
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

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(const StaticArray<char, 14>& array)
{
	for (int count{ 0 }; count < 14; ++count)
		std::cout << array[count];
}

int main()
{
    // Declare a char array
    StaticArray<char, 14> char14{};

    // Copy some data into it
    constexpr std::string_view hello{ "Hello, world!" };
    std::copy_n(hello.begin(), hello.size(), char14.getArray());

    // Print the array
    print(char14);

    return 0;
}
