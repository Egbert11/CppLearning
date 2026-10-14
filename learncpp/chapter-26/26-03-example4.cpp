// ============================================================
// 来源小节：26.3 Function template specialization（原 Example 4）
// 示例说明：类模板 Storage<T> 的普通成员函数 print()。这里 Storage i { 5 };
//           使用了 C++17 的类模板实参推导（CTAD），从 5 推出 T = int。
//           若要只改 double 的行为，就得特化整个类模板 Storage<double>，
//           而那不是“函数模板特化”（见下一节 26.4）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-specialization/
// 预期输出：
//   5
//   6.7
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

int main()
{
    // Define some storage units
    Storage i { 5 };
    Storage d { 6.7 };

    // Print out some values
    i.print();
    d.print();
}
