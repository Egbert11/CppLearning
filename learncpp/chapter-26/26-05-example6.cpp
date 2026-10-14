// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 11）
// 示例说明：解决方案 A——把整个类部分特化：StaticArray<double, size>。它的
//           print() 于是成了“部分特化类里的普通成员函数”，可以正常定义。
//           代价是代码重复较多（成员几乎照抄一遍）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出：
//   0 1 2 3 4 5
//   4.000000e+00 4.100000e+00 4.200000e+00 4.300000e+00
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T, int size>
class StaticArray
{
private:
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	const T& operator[](int index) const { return m_array[index]; }
	T& operator[](int index) { return m_array[index]; }

	void print() const;
};

template <typename T, int size>
void StaticArray<T, size>::print() const
{
	for (int i{ 0 }; i < size; ++i)
		std::cout << m_array[i] << ' ';
	std::cout << '\n';
}

// Partially specialized class
template <int size>
class StaticArray<double, size>
{
private:
	double m_array[size]{};

public:
	double* getArray() { return m_array; }

	const double& operator[](int index) const { return m_array[index]; }
	double& operator[](int index) { return m_array[index]; }

	void print() const;
};

// Member function of partially specialized class
template <int size>
void StaticArray<double, size>::print() const
{
	for (int i{ 0 }; i < size; ++i)
		std::cout << std::scientific << m_array[i] << ' ';
	std::cout << '\n';
}

int main()
{
	// declare an integer array with room for 6 integers
	StaticArray<int, 6> intArray{};

	// Fill it up in order, then print it
	for (int count{ 0 }; count < 6; ++count)
		intArray[count] = count;

	intArray.print();

	// declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray{};

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);

	doubleArray.print();

	return 0;
}
