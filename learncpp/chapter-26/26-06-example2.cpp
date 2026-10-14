// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 2）
// 示例说明：同一套类，换成用 double* 去实例化——会暴露隐藏缺陷：T 变成
//           double*，m_value 存的是地址副本，print() 于是打印出地址而非所指的值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期输出（一个指针地址，具体数值依实现/每次运行而定，不可复现）：
//   例如 0x7ffe164e0f50
// 备注：原文示例 2 是 main 片段，其上方已定义 Storage<T> 与 print<double> 特化；
//       此处补全上下文以便独立编译。代码取自原文 HTML 逐字抽取。
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
    double d { 1.2 };
    double *ptr { &d };

    Storage s { ptr };
    s.print();

    return 0;
}
