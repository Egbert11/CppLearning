// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 1）
// 示例说明：基础 Storage<T>，以及只为 double 做的成员函数全特化 print()。
//           用 CTAD 创建 Storage i { 5 } / Storage d { 6.7 }。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期输出：
//   5
//   6.700000e+000
// 备注：代码取自原文 HTML 逐字抽取（原文 main 结尾无 return，此处照实保留）。
// ============================================================
#include <iostream>

template <typename T>
class Storage
{
private:
    T m_value {};
public:
    Storage(T value)
      : m_value { value }
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

template<>
void Storage<double>::print() // fully specialized for type double
{
    std::cout << std::scientific << m_value << '\n';
}

int main()
{
    // Define some storage units
    Storage i { 5 };
    Storage d { 6.7 }; // will cause Storage<double> to be implicitly instantiated

    // Print out some values
    i.print(); // calls Storage<int>::print (instantiated from Storage<T>)
    d.print(); // calls Storage<double>::print (called from explicit specialization of Storage<double>::print())
}
