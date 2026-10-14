// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 3）
// 示例说明：StaticArray<T, size>（一个类型参数 + 一个表达式参数）以及它的
//           通用 print()——每个元素后面都打印一个空格。打印 int 数组一切正常。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出：
//   0 1 2 3
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T, int size> // size is a template non-type parameter
class StaticArray
{
private:
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
	// declare an int array
	StaticArray<int, 4> int4{};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;

	// Print the array
	print(int4);

	return 0;
}
