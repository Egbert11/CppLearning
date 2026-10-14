// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 4）
// 示例说明：设计缺陷——用同一个通用 print() 打印 char 数组时，字符之间也被
//           塞进空格，无法像 C 字符串那样连成一片。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出（字符间带空格，末尾还有一个空格）：
//   H e l l o ,   w o r l d !
// 备注：原文示例 4 是独立的 main 片段，其上方已定义好 StaticArray 与通用 print；
//       此处把上下文一并补全以便独立编译。代码取自原文 HTML 逐字抽取。
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
