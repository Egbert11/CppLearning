// ============================================================
// 来源小节：26.4 Class template specialization（原 Example 3）
// 示例说明：基础版 Storage<T>，本节的出发点——我们想只改它的 print() 行为。
//           使用 C++17 的 CTAD：Storage i { 5 } / Storage d { 6.7 }。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-specialization/
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
