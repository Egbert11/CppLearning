// ============================================================
// 来源小节：19.3 Destructors
// 示例说明：为拥有动态内存的类删除拷贝构造与拷贝赋值，避免二次释放
//           （原文 Tip：用 -Weffc++ 编译时的报错与解决办法）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/destructors/
// 预期输出：The value of element 5 is: 6
// 备注：本节代码为按原文描述重建（原文只给出两行 =delete 建议，此处并入完整类）。
//       对应 14.14 的 =delete 用法。
// ============================================================
#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray
{
private:
    int* m_array{};
    int m_length{};

public:
    IntArray(int length) // constructor
    {
        assert(length > 0);

        m_array = new int[static_cast<std::size_t>(length)]{};
        m_length = length;
    }

    ~IntArray() // destructor
    {
        delete[] m_array;
    }

    // 禁止拷贝：否则两个对象会持有同一块内存，析构时二次释放
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }

    int getLength() { return m_length; }
};

int main()
{
    IntArray ar ( 10 ); // allocate 10 integers
    for (int count{ 0 }; count < ar.getLength(); ++count)
        ar.setValue(count, count+1);

    std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

    return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here
