// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 6）
// 示例说明：缓解方案二——在主模板里放 static_assert，直接拒绝指针与 nullptr
//           类型（std::nullptr_t 不是指针类型，不会被 Storage<T*> 匹配，所以
//           检查必须放在主模板上才能同时拦住两者）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期：**编译失败**（s1 合法，但 s2、s3 触发 static_assert），请勿修复。
//   预期错误：static assertion failed: Storage<T*> and Storage<nullptr> disallowed
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>
#include <type_traits> // for std::is_pointer_v and std::is_null_pointer_v

template <typename T>
class Storage
{
    // Make sure T isn't a pointer or a std::nullptr_t
    static_assert(!std::is_pointer_v<T> && !std::is_null_pointer_v<T>, "Storage<T*> and Storage<nullptr> disallowed");

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
    double d { 1.2 };

    Storage s1 { d }; // ok
    s1.print();

    Storage s2 { &d }; // static_assert because T is a pointer
    s2.print();

    Storage s3 { nullptr }; // static_assert because T is a nullptr
    s3.print();

    return 0;
}
