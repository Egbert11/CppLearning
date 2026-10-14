// ============================================================
// 来源小节：19.3 Destructors
// 示例说明：IntArray 类在构造函数里动态分配数组、在析构函数里 delete[] 释放（RAII 雏形）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/destructors/
// 预期输出：The value of element 5 is: 6
// 备注：本节代码为按原文描述重建（原文的主示例）。
//       若用 -Weffc++ 编译会报 effc++ 警告（未定义拷贝构造/赋值），
//       解决办法见 19-03-example2.cpp。
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
        // Dynamically delete the array we allocated earlier
        delete[] m_array;
    }

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
