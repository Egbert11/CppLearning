// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：故意演示编译错误——自定义容器 IntArray 没有接收
//           std::initializer_list 的构造函数，因此
//           `IntArray array{ 5, 4, 3, 2, 1 };` 无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期错误：编译失败。典型 g++ 报错类似：
//   error: too many initializers for 'IntArray'
//   或 error: no matching function for call to 'IntArray::IntArray(<brace-enclosed initializer list>)'
//   （不同编译器措辞不同；本题教学重点即"花括号初始化需要列表构造函数"）。
// 备注：-error 后缀 = 预期编译失败。请勿"修复"此错误。
// ============================================================
#include <cassert>
#include <cstddef>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length)
        : m_length{ length }
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[static_cast<std::size_t>(length)]{};
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

int main()
{
    // 没有 std::initializer_list 构造函数，下面这行无法编译：
    IntArray array { 5, 4, 3, 2, 1 };

    return 0;
}
