// ============================================================
// 来源小节：26.4 Class template specialization（原 Example 1）
// 示例说明：通用的 Storage8<T>，内部用 T m_array[8] 存 8 个对象。
//           对 bool 来说每个 bool 占 1 字节（内存不可按位寻址），
//           于是 8 个 bool 浪费了 7/8 的空间——这正是需要用类模板特化优化的场景。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-specialization/
// 预期输出：
//   0 1 2 3 4 5 6 7（每行一个）
//   然后 false true true true false true true true（每行一个）
// 备注：代码取自原文 HTML 逐字抽取。原文中 `std::cout << std::boolalpha;` 一行
//       缩进与上方无花括号的 for 循环对齐，g++ -Wall 会给出 -Wmisleading-indentation
//       警告（1 条）；这是原文的排版，保留不动。
// ============================================================
#include <iostream>

template <typename T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(int index) const
    {
        return m_array[index];
    }
};

int main()
{
    // Define a Storage8 for integers
    Storage8<int> intStorage;

    for (int count{ 0 }; count < 8; ++count)
        intStorage.set(count, count);

    for (int count{ 0 }; count < 8; ++count)
        std::cout << intStorage.get(count) << '\n';

    // Define a Storage8 for bool
    Storage8<bool> boolStorage;
    for (int count{ 0 }; count < 8; ++count)
        boolStorage.set(count, count & 3);

	std::cout << std::boolalpha;

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }

    return 0;
}
