// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 5）
// 示例说明：可行的做法——偏特化整个类 Storage<T*>。这样 Storage<T*>::print()
//           就成了普通（非特化）成员函数，合法。参数声明为 T，故 T 会推成
//           非指针类型；偏特化必须定义在主模板之后。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期输出：
//   1.200000e+00
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T>
class Storage // This is our primary template class (same as previous)
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

template <typename T> // we still have a type template parameter
class Storage<T*> // This is partially specialized for T*
{
private:
    T* m_value {};
public:
    Storage(T* value)
      : m_value { value }
    {
    }

    void print();
};

template <typename T>
void Storage<T*>::print() // This is a non-specialized function of partially specialized class Storage<T*>
{
    if (m_value)
        std::cout << std::scientific << *m_value << '\n';
}

int main()
{
    double d { 1.2 };
    double *ptr { &d };

    Storage s { ptr }; // instantiates Storage<double*> from partially specialized class
    s.print(); // calls Storage<double*>::print()

    return 0;
}
