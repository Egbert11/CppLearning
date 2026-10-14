// 来源小节：21.x Chapter 21 summary and quiz（测验 3 解答）
// 示例说明：从零实现 IntArray（不使用 std::array / std::vector）：构造时确定长度并动态分配、
//           数组清零，用 assert 做边界检查。包含深拷贝的拷贝构造函数、释放内存的析构函数、
//           越界断言的 operator[]，以及带自赋值保护、先释放旧数组再重新分配的深拷贝 operator=。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
//        若缺少深拷贝会打印出垃圾值；若赋值运算符缺少自赋值检查或深拷贝，末尾会出现 7。
// 预期输出：
//   5 8 2 3 6
//   5 8 2 3 6

#include <cassert>
#include <iostream>

class IntArray
{
private:
    int m_length{};
    int* m_array{};

public:
    explicit IntArray(int length)
        : m_length{ length }
    {
        assert(length > 0);
        m_array = new int[static_cast<std::size_t>(length)]{};
    }

    IntArray(const IntArray& array)
        : m_length{ array.m_length }
    {
        // allocate a new array
        m_array = new int[static_cast<std::size_t>(m_length)];

        // copy elements
        for (int i{ 0 }; i < array.m_length; ++i)
            m_array[i] = array.m_array[i];
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
    {
        for (int i{ 0 }; i < array.m_length; ++i)
            out << array.m_array[i] << ' ';

        return out;
    }

    int& operator[](int index)
    {
        assert(index >= 0);
        assert(index < m_length);
        return m_array[index];
    }

    IntArray& operator=(const IntArray& array)
    {
        // self-assignment check
        if (this == &array)
            return *this;

        // if this array already has memory allocated, delete it
        delete[] m_array;

        m_length = array.m_length;

        // allocate a new array
        m_array = new int[static_cast<std::size_t>(m_length)];

        // copy elements
        for (int i{ 0 }; i < array.m_length; ++i)
            m_array[i] = array.m_array[i];

        return *this;
    }
};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
