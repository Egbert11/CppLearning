// ============================================================
// 来源小节：26.4 Class template specialization（原 Example 5）
// 示例说明：更好的做法——只特化成员函数 Storage<double>::print()，让编译器
//           仍旧从 Storage<T> 隐式实例化出 Storage<double> 的其余部分。
//           显式函数特化不是隐式 inline，放进头文件时要自己加 inline。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-specialization/
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

// This is a specialized member function definition
// Explicit function specializations are not implicitly inline, so make this inline if put in header file
template<>
void Storage<double>::print()
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
