// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 3）
// 示例说明：第一种修法——为 double* 做一个成员函数全特化，让它解引用后打印。
//           问题：对每种指针类型都得再写一份，且无法覆盖指向自定义类型的指针。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期输出：
//   1.200000e+00
// 备注：代码取自原文 HTML 逐字抽取。
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
void Storage<double*>::print() // fully specialized for type double*
{
    if (m_value)
        std::cout << std::scientific << *m_value << '\n';
}

template<>
void Storage<double>::print() // fully specialized for type double (for comparison, not used)
{
    std::cout << std::scientific << m_value << '\n';
}

int main()
{
    double d { 1.2 };
    double *ptr { &d };

    Storage s { ptr };
    s.print(); // calls Storage<double*>::print()

    return 0;
}
