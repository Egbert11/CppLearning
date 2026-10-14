// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：未定义行为演示——IntArray 有列表构造函数，但"没有"提供
//           深拷贝的拷贝赋值运算符（也没有 delete 它）。于是
//           `array = { 1, 3, 5, 7, 9, 11 };` 会：先用列表构造出一个
//           临时 IntArray，再用编译器隐式生成的"浅拷贝"赋值运算符把
//           其内部指针复制给 array。临时对象销毁时释放了同一块内存，
//           array 的 m_data 变成悬垂指针 → 释放/使用时是 UB（二次释放）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期：能编译；运行结果是 UB（本机 g++ 下的观测：先打印
//       "before assignment, length=5" 与 "after assignment, length=6"，
//       随后在读取被释放的内存时崩溃，退出码非 0）。不同实现/运行
//       结果不定（也可能印出垃圾值、或二次释放报错）。
// 备注：-ub 后缀 = 未定义行为演示（要求能编译）。
//       正确做法见 23-07-quiz1.cpp：提供列表赋值运算符（深拷贝），
//       或 delete 拷贝赋值/拷贝构造。
// ============================================================
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>

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

    IntArray(std::initializer_list<int> list)
        : IntArray(static_cast<int>(list.size()))
    {
        std::copy(list.begin(), list.end(), m_data);
    }

    // 注意：这里故意"没有"写拷贝构造/拷贝赋值（也没 delete），
    // 于是编译器生成浅拷贝的版本 —— 这正是 UB 的根源。

    ~IntArray() { delete[] m_data; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

int main()
{
    IntArray array { 5, 4, 3, 2, 1 };

    std::cout << "before assignment, length=" << array.getLength() << std::flush << '\n';

    array = { 1, 3, 5, 7, 9, 11 }; // 未定义行为：浅拷贝 + 临时对象析构释放内存

    std::cout << "after assignment (may never be reached), length=" << array.getLength() << std::flush << '\n';

    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    return 0;
}
