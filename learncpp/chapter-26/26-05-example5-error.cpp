// ============================================================
// 来源小节：26.5 Partial template specialization（原 Example 10）
// 示例说明：试图只偏特化成员函数 StaticArray<double, size>::print()——不允许。
//           “函数不能被偏特化”（截至 C++23），只有类可以。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/
// 预期：**编译失败**，请勿修复。
//   实测错误（GCC 15.2）：error: invalid use of incomplete type
//   'class StaticArray<double, size>' —— GCC 以“试图用不完整的（偏特化）类类型
//   来定义成员函数”的方式拒绝；语义即“成员函数/函数模板不能被偏特化”。
// 备注：原文示例 10 是片段，其上方的 StaticArray 定义见示例 9（下方已补全）。
//       代码取自原文 HTML 逐字抽取。
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

// Doesn't work, can't partially specialize functions
template <int size>
void StaticArray<double, size>::print() const
{
	for (int i{ 0 }; i < size; ++i)
		std::cout << std::scientific << m_array[i] << ' ';
	std::cout << '\n';
}

int main()
{
	StaticArray<double, 4> doubleArray{};
	doubleArray.print();

	return 0;
}
