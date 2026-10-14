// ============================================================
// 来源小节：26.6 Partial template specialization for pointers（原 Example 7）
// 示例说明：缓解方案三——让 Storage<T*> 持有一个 std::unique_ptr<T>，在堆上
//           拷贝一份所指对象，从而获得值语义，避免悬垂；也就不必手写构造/拷贝/
//           赋值/析构。主模板里仍有 static_assert 拦住裸指针与 nullptr 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
// 预期输出：
//   1.2
//   1.2
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>
#include <type_traits> // for std::is_pointer_v and std::is_null_pointer_v
#include <memory>

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

template <typename T>
class Storage<T*>
{
private:
    std::unique_ptr<T> m_value {}; // use std::unique_ptr to automatically deallocate when Storage is destroyed

public:
    Storage(T* value)
      : m_value { std::make_unique<T>(value ? *value : 0) } // or throw exception when !value
    {
    }

    void print()
    {
        if (m_value)
            std::cout << *m_value << '\n';
    }
};

int main()
{
    double d { 1.2 };

    Storage s1 { d }; // ok
    s1.print();

    Storage s2 { &d }; // ok, copies d on heap
    s2.print();

    return 0;
}
