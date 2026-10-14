// ============================================================
// 来源小节：26.4 Class template specialization（原 Example 4）
// 示例说明：仅仅为了改 print() 而把整个 Storage<double> 全特化一遍——很冗余。
//           注意全特化必须出现在主模板之后；类外定义 print() 就像定义普通
//           成员函数一样，不需要 template<>。
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

// Explicit class template specialization for Storage<double>
// Note how redundant this is
template <>
class Storage<double>
{
private:
    double m_value {};
public:
    Storage(double value)
      : m_value { value }
    {
    }

    void print();
};

// We're going to define this outside the class for reasons that will become obvious shortly
// This is a normal (non-specialized) member function definition (for member function print of specialized class Storage<double>)
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}

int main()
{
    // Define some storage units
    Storage i { 5 };
    Storage d { 6.7 }; // uses explicit specialization Storage<double>

    // Print out some values
    i.print(); // calls Storage<int>::print (instantiated from Storage<T>)
    d.print(); // calls Storage<double>::print (called from explicit specialization of Storage<double>)
}
