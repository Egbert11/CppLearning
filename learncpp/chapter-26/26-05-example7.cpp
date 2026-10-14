// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 13）
// 示例说明：解决方案 B——抽出公共基类 StaticArray_Base<T, size>，让通用版和
//           部分特化版都从它继承，从而避免大量重复代码。
//           注意：派生特化里访问基类成员必须写 this->m_array，因为模板中的
//           m_array 是非依赖名字，直接写会找不到（见原文注释中的链接）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期输出：与 example6 相同。
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T, int size>
class StaticArray_Base
{
protected:
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	const T& operator[](int index) const { return m_array[index]; }
	T& operator[](int index) { return m_array[index]; }

	void print() const
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << '\n';
	}

	// Don't forget a virtual destructor if you're going to use virtual function resolution
};

template <typename T, int size>
class StaticArray: public StaticArray_Base<T, size>
{
};

template <int size>
class StaticArray<double, size>: public StaticArray_Base<double, size>
{
public:

	void print() const
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << std::scientific << this->m_array[i] << ' ';
// note: The this-> prefix in the above line is needed.
// See https://stackoverflow.com/a/6592617 or https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members for more info on why.
		std::cout << '\n';
	}
};

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
