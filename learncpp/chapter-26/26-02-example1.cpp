// ============================================================
// 来源小节：26.2 Template non-type parameters（原 Example 1）
// 示例说明：非类型参数（non-type parameter）。`int size` 的取值在编译期由
//           constexpr 实参替换，因此 m_array 可以静态分配（无需 new）。
//           同时演示了带非类型参数的类，其成员函数在类外如何定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-non-type-parameters/
// 预期输出：
//   11 10 9 8 7 6 5 4 3 2 1 0
//   4.4 4.5 4.6 4.7
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T, int size> // size is an integral non-type parameter
class StaticArray
{
private:
    // The non-type parameter controls the size of the array
    T m_array[size] {};

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

// Showing how a function for a class with a non-type parameter is defined outside of the class
template <typename T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

int main()
{
    // declare an integer array with room for 12 integers
    StaticArray<int, 12> intArray;

    // Fill it up in order, then print it backwards
    for (int count { 0 }; count < 12; ++count)
        intArray[count] = count;

    for (int count { 11 }; count >= 0; --count)
        std::cout << intArray[count] << ' ';
    std::cout << '\n';

    // declare a double buffer with room for 4 doubles
    StaticArray<double, 4> doubleArray;

    for (int count { 0 }; count < 4; ++count)
        doubleArray[count] = 4.4 + 0.1 * count;

    for (int count { 0 }; count < 4; ++count)
        std::cout << doubleArray[count] << ' ';

    return 0;
}
