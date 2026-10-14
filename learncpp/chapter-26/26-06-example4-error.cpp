// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 4）
// 示例说明：试图只偏特化成员函数 Storage<T*>::print()——不合法。
//           "函数不能被偏特化"（截至 C++23），只有类可以。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期：**编译失败**，请勿修复。
//   实测错误（GCC 15.2）：error: invalid use of incomplete type
//   'class Storage<T*>' —— GCC 以“用不完整的（偏特化）类类型定义成员函数”的
//   方式拒绝；语义即“成员函数/函数模板不能被偏特化”。
// 备注：原文示例 4 是片段，其上方的 Storage 类定义与示例 1 相同（已在下方补全）。
//       代码取自原文 HTML 逐字抽取。
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

// doesn't work
template<typename T>
void Storage<T*>::print()
{
    if (m_value)
        std::cout << std::scientific << *m_value << '\n';
}

int main()
{
    double d { 1.2 };
    double *ptr { &d };

    Storage s { ptr };
    s.print();

    return 0;
}
